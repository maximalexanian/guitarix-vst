#define WIN32_LEAN_AND_MEAN             // Exclude rarely-used stuff from Windows headers
// Windows Header Files
#include <windows.h>

//const char* dll_path = "C:\\Program Files\\Guitarix\\";// "P:\\library\\vcpkg\\installed\\x64-windows\\debug\\bin\\";
const char* gx_name = "GuitarixVST.vst3"; //"P:\\output\\Guitarix\\x64\\Debug\\GuitarixVST.vst3";

char* dll_names[] = {
#ifdef _DEBUG
	"ucrtbased.dll",
	"vcruntime140d.dll",
	"vcruntime140_1d.dll",
	"msvcp140d.dll",
	"msvcp140_1d.dll",
#else
	"ucrtbase.dll",
	"vcruntime140.dll",
	"vcruntime140_1.dll",
	"msvcp140.dll",
	"msvcp140_1.dll",
#endif
	/*"libmp3lame.dll",
	"mpg123.dll",
	"opus.dll",*/
	"libffi.dll",

	"zstd.dll",
	"liblzma.dll",
#ifdef _DEBUG
	"bz2d.dll",
	"zlibd1.dll",
"boost_iostreams-vc143-mt-gd-x64-1_79.dll",
#else
	"bz2.dll",
	"zlib1.dll",
"boost_iostreams-vc143-mt-x64-1_79.dll",
#endif

"fftw3f.dll",
	/*
	"ogg.dll",
	"vorbis.dll",
		//"ogg.DLL",//
	"flac.dll",
		//"vorbis.DLL",//
	"vorbisenc.dll",
"sndfile.dll",
*/
#ifdef _DEBUG
	"pthreadVC3d.dll",
#else
	"pthreadVC3.dll",
#endif

"sigc-3.0.dll",

		"charset-1.dll",
	"iconv-2.dll",
#ifdef _DEBUG
	"pcred.dll",
#else
	"pcre.dll",
#endif
		//"libiconv.DLL",//
		//"libcharset.DLL",//
	"intl-8.dll",
"glib-2.0-0.dll",

//"LIBINTL.DLL",

	//"SIGC-2.0.DLL",//
	//"GLIB-2.DLL",//
		//"GLIB-2.DLL",//
	"gmodule-2.0-0.dll",//
		//"GLIB-2.DLL",//
	"gobject-2.0-0.dll",//
"glibmm-2.68-1.dll",


	//"GLIBMM.DLL",//
	//"SIGC-2.0.DLL",//
	//"GLIB-2.DLL",//
	//"gobject-2.DLL",//
		//"LIBINTL.DLL",//
		//"zlibd1.dll",//
		//"gobject-2.DLL",//
		//"gmodule-2.DLL",
		//"GLIB-2.DLL",//
	"gio-2.0-0.dll",
"giomm-2.68-1.dll",
};
const int dll_num = sizeof(dll_names) / sizeof(dll_names[0]);


HMODULE dll_h[dll_num];
HMODULE gx = NULL;

class IPluginFactory;

typedef IPluginFactory* (__stdcall *LPGetPluginFactory)();
LPGetPluginFactory lpGetPluginFactory = 0;

typedef bool(*LPInitDll)();
LPInitDll lpInitDll = 0, lpExitDll = 0;


BOOL APIENTRY DllMain( HMODULE hModule,
                       DWORD  ul_reason_for_call,
                       LPVOID lpReserved
                     )
{
    switch (ul_reason_for_call)
    {
    case DLL_PROCESS_ATTACH:
		{
		CHAR dll_path[2048];
		DWORD sz = sizeof(dll_path) / sizeof(dll_path[0]);
//		GetProfileString("Guitarix", "Guitarix\\InstallDir", "C:\\Program Files\\Guitarix\\123", dll_path, sizeof(dll_path) / sizeof(dll_path[0]));
		
		LONG result = RegGetValue(
			HKEY_LOCAL_MACHINE,
			"SOFTWARE\\Guitarix\\1",
			"InstallDir",        // Value
			RRF_RT_REG_SZ,  // Flags, REG_SZ
			0,              // Type, non specified
			dll_path, &sz);
			
		//CHAR dll_path[] = "P:\\library\\vcpkg\\installed\\x64-windows\\debug\\bin\\";
		int failed = 0;
		for (int i = 0; i < dll_num; i++)
		{
			char path[2048];
			strcpy(path, dll_path);
#ifdef _DEBUG
			strcat(path, "debug\\"); 
#endif
			strcat(path, dll_names[i]);
			dll_h[i] = ::LoadLibrary(path);
			if (dll_h[i] == NULL) 
				failed++;
		}
		
		char gx_path[2048];
		strcpy(gx_path, dll_path);
		strcat(gx_path, gx_name);

		//CHAR gx_path[] = "P:\\output\\Guitarix\\x64\\Debug\\GuitarixVSTCore.vst3";
		gx = ::LoadLibrary(gx_path);
		if (gx)
		{
			lpGetPluginFactory = (LPGetPluginFactory)::GetProcAddress(gx, "GetPluginFactory");
			lpInitDll = (LPInitDll)::GetProcAddress(gx, "InitDll");
			lpExitDll = (LPInitDll)::GetProcAddress(gx, "ExitDll");
		}
		else
			failed++;
		/*TCHAR msg[100];
		wsprintf(msg, "Nuber of DLLs failed to load: %d", failed);
		::MessageBox(NULL, msg, "Guitarix Load dlls", MB_OK);*/
		}
		break;
	case DLL_PROCESS_DETACH:
		if (gx)
			::FreeLibrary(gx);
		for (int i = 0; i < dll_num; i++)
			if (dll_h[i])
				::FreeLibrary(dll_h[i]);
		break;
	case DLL_THREAD_ATTACH:
    case DLL_THREAD_DETACH:
        break;
    }
    return TRUE;
}

extern "C" __declspec (dllexport) bool InitDll() 
{
	if (lpInitDll) return lpInitDll();
	return true;
}

extern "C" __declspec (dllexport) bool ExitDll()
{
	if (lpExitDll) return lpExitDll();
	return true;
}

extern "C" __declspec (dllexport) IPluginFactory* __stdcall GetPluginFactory()
{
	if (lpGetPluginFactory) return lpGetPluginFactory();
	/*
	#if JUCE_32BIT
	#pragma comment(linker, "/EXPORT:GetPluginFactory=_GetPluginFactory@0")
	#else
	#pragma comment(linker, "/EXPORT:GetPluginFactory=GetPluginFactory")
	#endif
	*/
	return 0;
}

