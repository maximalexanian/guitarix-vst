from __future__ import division
import numpy as np
import sympy as sp

class GNDclass(object):
    def __repr__(self):
        return "GND"
GND = GNDclass()

class NODESclass(object):
    def add_count(self, tc, conn, param): pass
    def process(self, p, conn, param, alpha): pass
    def __repr__(self): return "NODES"
NODES = NODESclass()

class Node(object):
    def __init__(self, nm, d):
        self.nm = nm
        self.d = d
    def __repr__(self):
        return "%s%s" % (self.nm, self.d or "")
    def __hash__(self):
        return hash((self.nm,self.d))
    def __eq__(self, o):
        if not isinstance(o, Node):
            return False
        return self.nm == o.nm and self.d == o.d
    def __call__(self, s, fact=1.0):
        return OutU(self, s, fact)
    def check(self, param):
        if param is None:
            raise ValueError("%s: no value defined" % self)

class INclass(Node):
    def __init__(self):
        Node.__init__(self, "IN", None)
    def add_count(self, tc, conn, param):
        self.conn = conn
        tc["V"] += len(conn)
        tc["I"] = len(conn)
    def process(self, p, conn, param, alpha):
        for i, c in enumerate(conn):
            idx = p.new_row("V", self, self.conn[i])
            p.S[idx, c] += 1
            p.S[c, idx] += 1
            n = p.new_row("I", self, self.conn[i])
            p.N["I"][n, idx] = 1
IN = INclass()


class Out(object):
    def __init__(self, node, fact=1.0):
        self.node = node
        self.fact = fact

    def get_index(self, p):
        return p.nodes[self.node], self.fact

    def __repr__(self):
        if self.fact != 1.0:
            return "%s*%g" % (self.node, self.fact)
        else:
            return repr(self.node)


class OutU(Out):
    def __init__(self, node, f, fact):
        self.node = node
        self.f = f
        self.fact = fact

    def get_index(self, p):
        return p.extra_variable_by_name((self.node,self.f)), self.fact

    def __repr__(self):
        return "%s%s" % (self.node, self.f and ("[%s]" % self.f) or "")

class OUTclass(Node):
    def __init__(self):
        Node.__init__(self, "OUT", None)
    def add_count(self, tc, conn, param):
        self.conn = conn
        tc["O"] += len(conn)
    def process(self, p, conn, param, alpha):
        for c in conn:
            v = 1
            if isinstance(c, Out):
                c, fact = c.get_index(p)
                v = fact
            p.N["O"][p.new_row("O", self), c] = v
OUT = OUTclass()

class R(Node):
    def __init__(self, n=None):
        Node.__init__(self, "R", n)
    def add_count(self, tc, conn, param):
        tc["R"] += 1
    def process(self, p, conn, param, alpha):
        idx = p.new_row("R", self)
        #param = sp.symbols(str(self))
        p.add_S_currents(conn, 1 / param)
        p.add_2conn("R", idx, conn)

class P_parallel(Node):
    # loga value     pot value for var = 0.5
    # log(16)        20%
    # 5              ~7.6%
    def __init__(self, n=None):
        Node.__init__(self, "P", n)
    def add_count(self, tc, conn, param):
        if conn[0] is not None and conn[1] is not None and conn[0] != conn[2] and conn[2] != conn[1]:
            tc["R"] += 2
            tc["P"] += 2
        else:
            tc["R"] += 1
            tc["P"] += 1
        tc["v"] += 1
    def process(self, p, conn, param, alpha):
        self.check(param)
        sym = str(self)+"v"
        if isinstance(param, dict):
            val = 2 * param["value"]
            sym = param.get("var", sym)
        else:
            val = 2 * param
        a = sp.symbols(sym)
        v = 1 / val
        # first resistor
        if conn[0] != conn[2] and conn[0] is not None:
            c = (conn[0], conn[2])
            idx1 = p.new_row("R", self)
            p.add_S_currents(c, v)
            p.add_2conn("R", idx1, c)
            idx_p1 = p.new_row("P", self, "+")
            p.add_2conn("P", idx_p1, c)
            p.Pv[idx_p1] = val
            p.pot_func[idx_p1] = (a, a / (2 - a))
        if conn[2] != conn[1] and conn[1] is not None:
            # second resistor
            c = (conn[2], conn[1])
            idx2 = p.new_row("R", self)
            p.add_S_currents(c, v)
            p.add_2conn("R", idx2, c)
            idx_p2 = p.new_row("P", self, "-")
            p.add_2conn("P", idx_p2, c)
            p.Pv[idx_p2] = val
            p.pot_func[idx_p2] = (a, (1 - a) / (1 + a))


class P_single(Node):
    def __init__(self, n=None):
        Node.__init__(self, "P", n)
    def add_count(self, tc, conn, param):
        if len(conn) == 3:
            tc["P"] += 2
        else:
            tc["P"] += 1
        tc["v"] += 1
    def process(self, p, conn, param, alpha):
        sym = str(self)+"v"
        if isinstance(param, dict):
            val = param["value"]
            sym = param.get("var", sym)
        else:
            val = param
        a = sp.symbols(sym)
        # first resistor
        c = (conn[0], conn[2])
        idx_p1 = p.new_row("P", self, "+")
        p.add_2conn("P", idx_p1, c)
        p.Pv[idx_p1] = val
        p.pot_func[idx_p1] = (a, a)
        if len(conn) == 3:
            # second resistor
            c = (conn[1], conn[2])
            idx_p2 = p.new_row("P", self, "-")
            p.add_2conn("P", idx_p2, c)
            p.Pv[idx_p2] = val
            p.pot_func[idx_p2] = (a, 1 - a)

class P_fixed(Node):
    def __init__(self, n=None):
        Node.__init__(self, "P", n)
    def add_count(self, tc, conn, param):
        if len(conn) == 3:
            tc["R"] += 2
        else:
            tc["R"] += 1
    def process(self, p, conn, param, alpha):
        if isinstance(param, dict):
            val = param["value"]
        else:
            val = param
        # first resistor
        c = (conn[0], conn[2])
        idx_p1 = p.new_row("R", self, "+")
        p.add_S_currents(conn, 2 / val)
        p.add_2conn("R", idx_p1, c)
        if len(conn) == 3:
            # second resistor
            c = (conn[1], conn[2])
            idx_p2 = p.new_row("R", self, "-")
            p.add_S_currents(conn, 2 / val)
            p.add_2conn("R", idx_p2, c)

P = P_parallel
#P = P_single
#P = P_fixed

class C(Node):
    def __init__(self, n=None):
        Node.__init__(self, "C", n)
    def add_count(self, tc, conn, param):
        tc["X"] += 1
    def process(self, p, conn, param, alpha):
        #print ("C = %s %s" % (param, alpha))
        idx = p.new_row("X", self)
        #param = sp.symbols(str(self))
        value = alpha * param
        #print ("C value = %s " % value)
        p.add_S_currents(conn, value)
        p.add_2conn("Xl", idx, conn, value)
        p.add_2conn("Xr", idx, conn)
        p.Z[idx] = 1

class L(Node):
    def __init__(self, n=None):
        Node.__init__(self, "L", n)
    def add_count(self, tc, conn, param):
        tc["X"] += 1
    def process(self, p, conn, param, alpha):
        #print ("L = %s %s" % (param, alpha))
        idx = p.new_row("X", self)
        #param = sp.symbols(str(self))
        #value = 1 / (alpha*2 * param)
        value = 1 / (alpha * param)
        #print ("L value = %s " % value)
        p.add_S_currents(conn, value)
        p.add_2conn("Xl", idx, conn, value)
        p.add_2conn("Xr", idx, conn)
        p.Z[idx] = -1

class D(Node):
    def __init__(self, n=None):
        Node.__init__(self, "D", n)
    def add_count(self, tc, conn, param):
        tc["N"] += 1
    def process(self, p, conn, param, alpha):
        if 'N' in param: # new model: mUt (Vt) = thermal voltage N = Emission coefficient
            Is, mUt, N = const = sp.symbols("Is,mUt,N")
            v0, = v = sp.symbols("v:1", seq=True)
            calc = -Is * (sp.exp(v0/(mUt*N)) - 1)
        else: # old model mUt = (N * Vt)
            Is, mUt = const = sp.symbols("Is,mUt")
            v0, = v = sp.symbols("v:1", seq=True)
            calc = -Is * (sp.exp(v0/mUt) - 1)
        calc = calc.subs(dict([(k,param[str(k)]) for k in const]))
        idx = p.new_row("N", self)
        p.add_2conn("Nl", idx, conn)
        p.add_2conn("Nr", idx, conn)
        p.set_function(idx, calc, v, idx)

class D2(Node):
    def __init__(self, n=None):
        Node.__init__(self, "D", n)
    def add_count(self, tc, conn, param):
        tc["N"] += 1
    def process(self, p, conn, param, alpha):
        if 'N' in param: # new model: mUt (Vt) = thermal voltage N = Emission coefficient
            Is, mUt, N = const = sp.symbols("Is,mUt,N")
            v0, = v = sp.symbols("v:1", seq=True)
            calc = -2 * Is * sp.sinh(v0/(mUt*N))
        else: # old model mUt = (N * Vt)
            Is, mUt = const = sp.symbols("Is,mUt")
            v0, = v = sp.symbols("v:1", seq=True)
            calc = -2 * Is * sp.sinh(v0/mUt)
        calc = calc.subs(dict([(k,param[str(k)]) for k in const]))
        idx = p.new_row("N", self)
        p.add_2conn("Nl", idx, (conn[0], conn[1]))
        p.add_2conn("Nr", idx, (conn[0], conn[1]))
        p.set_function(idx, calc, v, idx)

class VCCS(Node):
    def __init__(self, n=None):
        Node.__init__(self, "VCCS", n)
    def add_count(self, tc, conn, param):
        pass
    def process(self, p, conn, param, alpha):
        dG = param["dG"]
        i0 = param["i0"]
        if conn[2] != -1:
            if conn[0] != -1:
                p.S[conn[2], conn[0]] += dG
            if conn[1] != -1:
                p.S[conn[2], conn[1]] -= dG
            p.ConstVoltages[0,conn[2]] += i0
        if conn[3] != -1:
            if conn[0] != -1:
                p.S[conn[3], conn[0]] -= dG
            if conn[1] != -1:
                p.S[conn[3], conn[1]] += dG
            p.ConstVoltages[0,conn[3]] -= i0

class T(Node):
    def __init__(self, n=None):
        Node.__init__(self, "T", n)
    def add_count(self, tc, conn, param):
        tc["N"] += 2
    def process(self, p, conn, param, alpha):
        # pins are C, B, E (index 0, 1, 2)
        # Ib and Ie depend on Vbc (1 - 0) and Vbe (1 - 2), Ic = Ib + Ie
        # 
        Is, Bf, Vt, Br = const = sp.symbols("Is,Bf,Vt,Br")
        Vbc, Vbe = v = sp.symbols("Vbc,Vbe")
        calc_ib = -(Is / Bf * (sp.exp(Vbe/Vt)-1) + Is/Br * (sp.exp(Vbc/Vt)-1))
        calc_ib = calc_ib.subs(dict([(k,param[str(k)]) for k in const]))
        calc_ie = -(-Is*(sp.exp(Vbe/Vt)-1) + Is*(Br-1)/Br * (sp.exp(Vbc/Vt)-1))
        calc_ie = calc_ie.subs(dict([(k,param[str(k)]) for k in const]))
        idx1 = p.new_row("N", self, "Ib")
        p.add_2conn("Nl", idx1, (conn[1],conn[0]))
        p.add_2conn("Nr", idx1, (conn[1],conn[0]))
        p.set_function(idx1, calc_ib, v, idx1)
        idx2 = p.new_row("N", self, "Ie")
        p.add_2conn("Nl", idx2, (conn[1],conn[2]))
        p.add_2conn("Nr", idx2, (conn[2],conn[0]))
        p.set_function(idx2, calc_ie, v, idx1)

class Tp(Node):
    def __init__(self, n=None):
        Node.__init__(self, "T", n)
    def add_count(self, tc, conn, param):
        tc["N"] += 2
    def process(self, p, conn, param, alpha):
        # pins are C, B, E (index 0, 1, 2)
        # Ib and Ie depend on Vbc (1 - 0) and Vbe (1 - 2), Ic = Ie - Ib
        # 
        Is, Bf, Vt, Br = const = sp.symbols("Is,Bf,Vt,Br")
        Vbc, Vbe = v = sp.symbols("Vbc,Vbe")
        calc_ib = -(Is / Bf * (sp.exp(Vbe/Vt)-1) + Is/Br * (sp.exp(Vbc/Vt)-1))
        calc_ib = calc_ib.subs(dict([(k,param[str(k)]) for k in const]))
        calc_ie = -(-Is*(sp.exp(Vbe/Vt)-1) + Is*(Br-1)/Br * (sp.exp(Vbc/Vt)-1))
        calc_ie = calc_ie.subs(dict([(k,param[str(k)]) for k in const]))
        idx1 = p.new_row("N", self, "Ib")
        p.add_2conn("Nl", idx1, (conn[0],conn[1]))
        p.add_2conn("Nr", idx1, (conn[0],conn[1]))
        p.set_function(idx1, calc_ib, v, idx1)
        idx2 = p.new_row("N", self, "Ie")
        p.add_2conn("Nl", idx2, (conn[2],conn[1]))
        p.add_2conn("Nr", idx2, (conn[0],conn[2]))
        p.set_function(idx2, calc_ie, v, idx1)

class Triode(Node):
    def __init__(self, n=None):
        Node.__init__(self, "Triode", n)
    def add_count(self, tc, conn, param):
        tc["N"] += 2
    def process(self, p, conn, param, alpha):
        mu, Ex, Kp, Kvb, Kg1, Gco, Gcf = const = sp.symbols("mu,Ex,Kp,Kvb,Kg1,Gco,Gcf")
        Ugk, Uak = v = sp.symbols("Ugk,Uak", real=True) # "real" needed to get derivative of sign()
        t = Kp*(1/mu+Ugk/sp.sqrt(Kvb+Uak*Uak))
        E1 = Uak/Kp*sp.log(1+sp.exp(t))
        E1_ = Uak/Kp*t
        calc_Ia = sp.Piecewise(
            (0, Uak < 0),
            (0, t < -500),
            (-pow(E1_,Ex) / Kg1 * (1+sp.sign(E1_)), t > 500),
            (-pow(E1,Ex) / Kg1 * (1+sp.sign(E1)), True))
        calc_Ia = calc_Ia.subs(dict([(k,param[str(k)]) for k in const]))
        calc_Ig = sp.Piecewise((0, Ugk < Gco), (-Gcf*pow(Ugk-Gco, 1.5), True))
        calc_Ig = calc_Ig.subs(dict([(k,param[str(k)]) for k in const]))
        # def calc_Ia(v):
        #     Ugk = float(v[0])
        #     Uak = float(v[1])
        #     if Uak < 0:
        #         return 0
        #     t = Kp*(1/mu+Ugk/math.sqrt(Kvb+Uak*Uak))
        #     if t > 500:
        #         E1 = Uak/Kp*t
        #     elif t < -500:
        #         return 0
        #     else:
        #         E1 = Uak/Kp*math.log(1+math.exp(t))
        #     r = pow(E1,Ex) / Kg1 * 2*(E1 > 0.0)
        #     return -r
        # def calc_Ig(v):
        #     Ugk = float(v[0])
        #     if Ugk < Gco:
        #         return 0
        #     r = Gcf*pow(Ugk-Gco, 1.5)
        #     return -r
        idx1 = p.new_row("N", self, "Ig")
        p.add_2conn("Nl", idx1, (conn[0],conn[2]))
        p.add_2conn("Nr", idx1, (conn[0],conn[2]))
        p.set_function(idx1, calc_Ig, v, idx1)
        idx2 = p.new_row("N", self, "Ip")
        p.add_2conn("Nl", idx2, (conn[1],conn[2]))
        p.add_2conn("Nr", idx2, (conn[1],conn[2]))
        p.set_function(idx2, calc_Ia, v, idx1)

class Pentode(Node):
    def __init__(self, n=None):
        Node.__init__(self, "Pentode", n)
    def add_count(self, tc, conn, param):
        tc["N"] += 3
    def process(self, p, conn, param, alpha):
        mu, Ex, Kp, Kg1, Kg2, Kvb, Gco, Gcf = const = sp.symbols("mu,Ex,Kp,Kg1,Kg2,Kvb,Gco,Gcf")
        Ug1k, Ug2k, Uak = v = sp.symbols("Ug1k,Ug2k,Uak")
        t = Kp * (1 / mu + Ug1k / Ug2k)
        E1 = Ug2k / Kp * sp.log(1 + sp.exp(t))
        E1_ = Ug2k / Kp * t
        #sign = sp.sign
        sign = lambda x: 2 * sp.Heaviside(x) - 1
        calc_Ia = sp.Piecewise(
            (0, Ug2k <= 0),
            (0, t < -500),
            (-pow(E1_,Ex)/Kg1 * (1+sign(E1_)) * sp.atan(Uak/Kvb), t > 500),
            (-pow(E1,Ex)/Kg1 * (1+sign(E1)) * sp.atan(Uak/Kvb), True))
        calc_Ia = calc_Ia.subs(dict([(k,param[str(k)]) for k in const]))
        calc_Ig = sp.Piecewise((0, Ug1k < Gco), (-Gcf*pow(Ug1k-Gco, 1.5), True))
        calc_Ig = calc_Ig.subs(dict([(k,param[str(k)]) for k in const]))
        t = Ug2k / mu + Ug1k
        calc_Is = sp.Piecewise((0, t <= 0), (-sp.exp(Ex*sp.log(t)) / Kg2, True))
        calc_Is = calc_Is.subs(dict([(k,param[str(k)]) for k in const]))
        # def calc_Ia(v):
        #     Ug1k = float(v[0])
        #     Ug2k = float(v[1])
        #     Uak = float(v[2])
        #     if Ug2k <= 0.0:
        #         return 0
        #     t = Kp * (1 / mu + Ug1k / Ug2k)
        #     if t > 500:
        #         E1 = Ug2k / Kp * t
        #     elif t < -500:
        #         return 0
        #     else:
        #         E1 = Ug2k / Kp * math.log(1 + math.exp(t))
        #     r = pow(E1,Ex)/Kg1 * 2*(E1 > 0.0) * math.atan(Uak/Kvb);
        #     #print Ug1k, Ug2k, Uak, r
        #     return -r
        # def calc_Ig(v):
        #     Ugk = float(v[0])
        #     if Ugk < Gco:
        #         return 0
        #     r = Gcf*pow(Ugk-Gco, 1.5)
        #     return -r
        # def calc_Is(v):
        #     Ug1k = float(v[0])
        #     Ug2k = float(v[1])
        #     t = Ug2k / mu + Ug1k
        #     if t <= 0:
        #         return 0
        #     r = math.exp(Ex*math.log(t)) / Kg2
        #     return -r

        idx1 = p.new_row("N", self, "Ig")
        p.add_2conn("Nl", idx1, (conn[0],conn[3]))
        p.add_2conn("Nr", idx1, (conn[0],conn[3]))
        p.set_function(idx1, calc_Ig, v[:1], idx1)
        idx2 = p.new_row("N", self, "Is")
        p.add_2conn("Nl", idx2, (conn[1],conn[3]))
        p.add_2conn("Nr", idx2, (conn[1],conn[3]))
        p.set_function(idx2, calc_Is, v, idx1)
        idx3 = p.new_row("N", self, "Ip")
        p.add_2conn("Nl", idx3, (conn[2],conn[3]))
        p.add_2conn("Nr", idx3, (conn[2],conn[3]))
        p.set_function(idx3, calc_Ia, v, idx1)

class Trans_L(Node):
    def __init__(self, n=None, nw=3):
        self.nw = nw
        Node.__init__(self, "TL", n)
    def add_count(self, tc, conn, param):
        tc["X"] += 1
        tc["V"] += self.nw + 2
    def process(self, p, conn, param, alpha):
        start = p.current_row("V") + 1
        end = start + self.nw + 1
        for i in range(self.nw):
            s = "W%d" % (i+1)
            idx = p.new_row("V", self, s)
            p.add_S(idx, conn[2*i:], 1)
            p.S[idx, end] += param["windings"][i]
        idx = p.new_row("V", self, "phi")
        vps = np.array(p.S[idx, start:end-1])
        vps += np.array(np.array(param["windings"]))
        p.S[idx, start:end-1] = vps
        p.S[idx, end-1] += param["R"]
        idx_v = p.new_row("V", self, "v")
        p.S[idx_v, idx_v] += 1
        p.S[idx_v, idx] += alpha
        idx_xv = p.new_row("X", self, "v")
        p.N["Xl"][idx_xv, idx] = alpha
        p.N["Xr"][idx_xv, idx_v] = 1
        p.Z[idx_xv] = 1

class SingleTrans_L(Node):
    def __init__(self, n=None, nw=2):
        self.nw = nw
        Node.__init__(self, "STL", n)
    def add_count(self, tc, conn, param):
        tc["X"] += 1
        tc["V"] += self.nw + 2
    def process(self, p, conn, param, alpha):
        start = p.current_row("V") + 1
        end = start + self.nw + 1
        for i in range(self.nw):
            s = "W%d" % (i+1)
            idx = p.new_row("V", self, s)
            p.add_S(idx, conn[2*i:], 1)
            p.S[idx, end] += param["windings"][i]
        idx = p.new_row("V", self, "phi")
        vps = np.array(p.S[idx, start:end-1])
        vps += np.array(np.array(param["windings"]))
        p.S[idx, start:end-1] = vps
        p.S[idx, end-1] += param["R"]
        idx_v = p.new_row("V", self, "v")
        p.S[idx_v, idx_v] += 1
        p.S[idx_v, idx] += alpha
        idx_xv = p.new_row("X", self, "v")
        p.N["Xl"][idx_xv, idx] = alpha
        p.N["Xr"][idx_xv, idx_v] = 1
        p.Z[idx_xv] = 1

class Trans_F(Node):
    def __init__(self, n=None, nw=3):
        self.nw = nw
        Node.__init__(self, "TF", n)
    def add_count(self, tc, conn, param):
        tc["X"] += 1
        tc["V"] += self.nw + 2
        tc["N"] += 1
    def process(self, p, conn, param, alpha):
        b, c = const = sp.symbols("b,c")
        v0, = v = sp.symbols("v:1", seq=True)
        calc_frohlich = -(c * v0) / (1 - b * abs(v0))
        calc_frohlich = calc_frohlich.subs(dict([(k,param[str(k)]) for k in const]))
        # def calc_frohlich(v):
        #     v = float(v[0])
        #     #b = 255.
        #     #c = 358.
        #     r = (c * v) / (1 - b * abs(v))
        #     return -r
        start = p.current_row("V") + 1
        end = start + self.nw + 1
        for i in range(self.nw):
            s = "W%d" % (i+1)
            idx = p.new_row("V", self, s)
            p.add_S(idx, conn[2*i:], 1)
            p.S[idx, end] += param["windings"][i]
        idx = p.new_row("V", self, "phi")
        vps = np.array(p.S[idx, start:end-1])
        vps += np.array(np.array(param["windings"]))
        p.S[idx, start:end-1] = vps
        idx_v = p.new_row("V", self, "v")
        p.S[idx_v, idx_v] += 1
        p.S[idx_v, idx] += alpha
        idx_xv = p.new_row("X", self, "v")
        p.N["Xl"][idx_xv, idx] = alpha
        p.N["Xr"][idx_xv, idx_v] = 1
        p.Z[idx_xv] = 1
        idx = p.new_row("N", self, "phi")
        p.N["Nl"][idx, end-1] = 1
        p.N["Nr"][idx, end-1] = 1
        p.set_function(idx, calc_frohlich, v, idx)

class Trans_GC(Node):
    def __init__(self, n=None, nw=3):
        self.nw = nw
        Node.__init__(self, "TG", n)
    def add_count(self, tc, conn, param):
        tc["X"] += 1
        tc["V"] += self.nw + 2
        tc["N"] += 1
    def process(self, p, conn, param, alpha):
        windings = np.array(param["windings"], dtype=np.float64)
        if self.nw == 1:
            # avoid some convergence problems by scaling N to 1
            wind = windings[0]
            windings /= wind
            param = dict(C = param["C"] * wind**2,
                         a = param["a"] * wind**(param["n"]-1),
                         o = param["o"] * wind**-1,
                         n = param["n"],
                         )
        C, a, o, n = const = sp.symbols("C,a,o,n")
        phi, = v = sp.symbols("phi", seq=True, real=True) # "real" needed to get derivative of sign()
        t = phi / C
        calc_gc_MMF = -(a * pow(abs(t), n) * sp.sign(t)) + o
        calc_gc_MMF = calc_gc_MMF.subs(dict([(k,param[str(k)]) for k in const]))
        # def calc_gc_MMF(v):
        #     v = float(v[0])
        #     #C = 2e-3
        #     #a = 1e-5
        #     #n = 25
        #     t = v / C
        #     if v >= 0:
        #         t2 = pow(t, n)
        #     else:
        #         t2 = -pow(-t, n)
        #     r = -(t + a * t2)
        #     return r
        start = p.current_row("V") + 1
        end = start + self.nw + 1
        for i in range(self.nw):
            s = "W%d" % (i+1)
            idx = p.new_row("V", self, s)
            p.add_S(idx, conn[2*i:], 1)
            p.S[idx, end] += windings[i]
        idx = p.new_row("V", self, "phi")
        for i in range(self.nw):
            p.S[idx, start+i] += windings[i]
        p.S[idx, end-1] += 1 / param["C"]
        idx_v = p.new_row("V", self, "v")
        p.S[idx_v, idx_v] += 1
        p.S[idx_v, idx] += alpha
        idx_xv = p.new_row("X", self, "v")
        p.N["Xl"][idx_xv, idx] = alpha
        p.N["Xr"][idx_xv, idx_v] = 1
        p.Z[idx_xv] = 1
        idx = p.new_row("N", self, "phi")
        p.N["Nl"][idx, end-1] = 1
        p.N["Nr"][idx, end-1] = 1
        p.set_function(idx, calc_gc_MMF, v, idx)

class V(Node):
    def __init__(self, n=None):
        Node.__init__(self, "V", n)
    def add_count(self, tc, conn, param):
        tc["V"] += 1
        tc["C"] += 1
    def process(self, p, conn, param, alpha):
        idx = p.new_row("V", self)
        p.S[idx, conn[0]] += 1
        p.S[conn[0], idx] += 1
        p.ConstVoltages[0,idx] += param

class OPA(Node):
    def __init__(self, n=None):
        Node.__init__(self, "OPA_L", n)
    def add_count(self, tc, conn, param):
        tc["V"] += 1
        if isinstance(param, dict) and "Vcc" in param:
            tc["N"] += 1
    def process(self, p, conn, param, alpha):
        idx_s = p.new_row("V", self)
        p.S[idx_s, conn[2]] += 1
        p.S[conn[2], idx_s] += 1
        if isinstance(param, dict) and "Vcc" in param:
            Vcc, Vee, A = const = sp.symbols("Vcc,Vee,A")
            v0, = v = sp.symbols("v:1", seq=True)
            a = 2*A/(Vcc-Vee)
            calc = 0.5 * (sp.tanh(a*v0) * (Vcc-Vee) + Vcc + Vee)
            calc = calc.subs(dict([(k,param[str(k)]) for k in const]))
            idx = p.new_row("N", self)
            p.add_conn("Nl", idx, conn[0], 1)
            p.add_conn("Nl", idx, conn[1], -1)
            p.add_conn("Nr", idx, idx_s, 1)
            p.set_function(idx, calc, v, idx)
        else:
            if isinstance(param, dict):
                param = param["A"]
            p.S[idx_s, conn[0]] += param
            p.S[idx_s, conn[1]] += -param

class CC_L(Node):
    def __init__(self, n=None):
        Node.__init__(self, "CC", n)
    def add_count(self, tc, conn, param):
        tc["V"] += 1
    def process(self, p, conn, param, alpha):
        idx = p.new_row("V", self)
        p.S[conn[0], idx] += 1
        p.S[conn[1], idx] -= 1
        p.S[idx, conn[0]] += 1
        p.S[idx, conn[1]] -= 1

class CC_N(Node):
    def __init__(self, n=None):
        Node.__init__(self, "CC", n)
    def add_count(self, tc, conn, param):
        tc["N"] += 1
    def process(self, p, conn, param, alpha):
        v0, = v = sp.symbols("v:1", seq=True)
        calc = v0
        idx = p.new_row("N", self)
        p.add_2conn("Nl", idx, conn)
        p.add_2conn("Nr", idx, conn)
        p.set_function(idx, calc, v, idx)
        p.CZ[idx] = 0

#CC = CC_L
CC = CC_N
