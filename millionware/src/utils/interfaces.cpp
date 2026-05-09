#include "../utils/interfaces.hpp"

create_interface_fn get_module_factory(HMODULE module)
{
    return reinterpret_cast<create_interface_fn>(GetProcAddress(module, "CreateInterface"));
}

void* get_interface(HMODULE module, const char* interface_version)
{
    create_interface_fn factory = get_module_factory(module);
    return reinterpret_cast<void*>(factory(interface_version, nullptr));
}

std::unordered_map<uint32_t, std::string> g_interfaces;

void init_interfaces()
{
    g_interfaces.emplace(0x61A0F0D4, "engine.VEngineRandom001");
    g_interfaces.emplace(0x5C3C789C, "client.VCLIENTTOOLS001");
    g_interfaces.emplace(0x5F04AFA8, "vgui2.VGUI_InputInternal001");
    g_interfaces.emplace(0x61C6CB70, "engine.BlackBoxVersion001");
    g_interfaces.emplace(0x5C37F378, "client.GameUI011");
    g_interfaces.emplace(0x61A10F58, "engine.VSERVERENGINETOOLS001");
    g_interfaces.emplace(0x5F1547D0, "vguimatsurface.VGUI_Surface031");
    g_interfaces.emplace(0x619FFEB4, "engine.VPhysicsDebugOverlay001");
    g_interfaces.emplace(0x6198E6DC, "engine.IEngineSoundServer003");
    g_interfaces.emplace(0x6E32AC38, "inputsystem.InputStackSystemVersion001");
    g_interfaces.emplace(0x6E4B03D0, "filesystem_stdio.QueuedLoaderVersion001");
    g_interfaces.emplace(0x61A07404, "engine.EngineTraceClient004");
    g_interfaces.emplace(0x619FFEB0, "engine.VDebugOverlay004");
    g_interfaces.emplace(0x61A0F8E8, "engine.FileLoggingListener001");
    g_interfaces.emplace(0x5F79D5E8, "materialsystem.MaterialSystemHardwareConfig013");
    g_interfaces.emplace(0x64D4A688, "engine.StaticPropMgrServer002");
    g_interfaces.emplace(0x61A0634C, "engine.BugReporterUserName001");
    g_interfaces.emplace(0x5F760004, "materialsystem.ShaderSystem002");
    g_interfaces.emplace(0x61A01CF4, "engine.VEngineEffects001");
    g_interfaces.emplace(0x57F0A470, "client.IEffects001");
    g_interfaces.emplace(0x6C8B2980, "datacache.VResourceAccessControl001");
    g_interfaces.emplace(0x6E4AFF28, "filesystem_stdio.VNewAsyncFileSystem001");
    g_interfaces.emplace(0x61A07818, "engine.GAMEEVENTSMANAGER001");
    g_interfaces.emplace(0x6C8A4F18, "datacache.MDLCache004");
    g_interfaces.emplace(0x61A0D560, "engine.VModelInfoClient004");
    g_interfaces.emplace(0x6C8A4E20, "datacache.VDataCache003");
    g_interfaces.emplace(0x61A10F5C, "engine.VTOOLFRAMEWORKVERSION002");
    g_interfaces.emplace(0x6E4AFFAC, "filesystem_stdio.VBaseFileSystem011");
    g_interfaces.emplace(0x5F79D4D0, "materialsystem.ShaderDLL004");
    g_interfaces.emplace(0x57C562DC, "tier0>g_pMemAlloc");
    g_interfaces.emplace(0x5C37DF28, "client.VClientPrediction001");
    g_interfaces.emplace(0x61A10E40, "engine.XboxSystemInterface002");
    g_interfaces.emplace(0x6C89A3C0, "datacache.VPrecacheSystem001");
    g_interfaces.emplace(0x57F04EB8, "client.ClientRenderTargets001");
    g_interfaces.emplace(0x6198E65C, "engine.IEngineSoundClient003");
    g_interfaces.emplace(0x57F218CC, "client.VGuiModuleLoader003");
    g_interfaces.emplace(0x5F75FE48, "materialsystem.VMaterialSystemStub001");
    g_interfaces.emplace(0x64D4A3D0, "engine.SpatialPartition001");
    g_interfaces.emplace(0x745C9A10, "vstdlib.EventSystem001");
    g_interfaces.emplace(0x57C562DC, "tier0>g_pMemAlloc");
    g_interfaces.emplace(0x5C37B010, "client.GameMovement001");
    g_interfaces.emplace(0x61A10FB0, "engine.VCLIENTENGINETOOLS001");
    g_interfaces.emplace(0x61A0EE90, "engine.VEngineClientStringTable001");
    g_interfaces.emplace(0x5F040670, "vgui2.VGUI_System010");
    g_interfaces.emplace(0x5F65FE98, "studiorender.VStudioRender026");
    g_interfaces.emplace(0x5BF50100, "client.ClientLeafSystem002");
    g_interfaces.emplace(0x5F8CAA5C, "vphysics.VPhysicsCollision007");
    g_interfaces.emplace(0x5F75DE10, "materialsystem.COLORCORRECTION_VERSION_1");
    g_interfaces.emplace(0x64D4CE58, "engine.VENGINETOOLFRAMEWORK003");
    g_interfaces.emplace(0x5BF5010C, "client.ClientAlphaPropertyMgrV001");
    g_interfaces.emplace(0x61A05B48, "engine.VEngineServer023");
    g_interfaces.emplace(0x64D4A684, "engine.StaticPropMgrClient005");
    g_interfaces.emplace(0x5F04AFA8, "vgui2.VGUI_InputInternal001");
    g_interfaces.emplace(0x61A07510, "engine.EngineTraceServer004");
    g_interfaces.emplace(0x61C7C4C8, "engine.GAMEEVENTSMANAGER002");
    g_interfaces.emplace(0x61BE4720, "engine.VEngineModel016");
    g_interfaces.emplace(0x5F75F8A0, "materialsystem.VMaterialSystemConfig004");
    g_interfaces.emplace(0x61A0EECC, "engine.VEngineServerStringTable001");
    g_interfaces.emplace(0x61A0FF8C, "engine.VENGINE_GAMEUIFUNCS_VERSION005");
    g_interfaces.emplace(0x61A04518, "engine.ISERVERPLUGINHELPERS001");
    g_interfaces.emplace(0x619FD3E8, "engine.VEngineClient014");
    g_interfaces.emplace(0x57F08CF8, "client.VCLIENTMATERIALSYSTEM001");
    g_interfaces.emplace(0x5F8D6078, "vphysics.VPhysicsSurfaceProps001");
    g_interfaces.emplace(0x5C6CDC48, "matchmaking.VENGINE_GAMETYPES_VERSION002");
    g_interfaces.emplace(0x61A0E1CC, "engine.INETSUPPORT_003");
    g_interfaces.emplace(0x61A10728, "engine.VoiceServer002");
    g_interfaces.emplace(0x5F8CAA20, "vphysics.VPhysics031");
    g_interfaces.emplace(0x745CF6AC, "vstdlib.VProcessUtils002");
    g_interfaces.emplace(0x5F04C498, "vgui2.VGUI_ivgui008");
    g_interfaces.emplace(0x61A01D14, "engine.VEngineRenderView014");
    g_interfaces.emplace(0x57F118D0, "client.VParticleSystemQuery004");
    g_interfaces.emplace(0x64D4CE58, "engine.VENGINETOOLFRAMEWORK003");
    g_interfaces.emplace(0x61A10768, "engine.VProfExport001");
    g_interfaces.emplace(0x64D4D0F8, "engine.VEngineVGui001");
    g_interfaces.emplace(0x5BF3FFB4, "client.VClientEntityList003");
    g_interfaces.emplace(0x5F04C2D0, "vgui2.VGUI_Scheme010");
    g_interfaces.emplace(0x61A0FF90, "engine.VENGINE_HLDS_API_VERSION002");
    g_interfaces.emplace(0x61A06B98, "engine.VCvarQuery001");
    g_interfaces.emplace(0x57F08A18, "client.GameClientExports001");
    g_interfaces.emplace(0x5F0408C4, "vgui2.VGUI_Panel009");
    g_interfaces.emplace(0x5BF1AC40, "client.VClientDllSharedAppSystems001");
    g_interfaces.emplace(0x61C09180, "engine.VEngineShadowMgr002");
    g_interfaces.emplace(0x61A10030, "engine.VENGINE_LAUNCHER_API_VERSION004");
    g_interfaces.emplace(0x5CEE8A70, "localize.Localize_001");
    g_interfaces.emplace(0x5C6BA3F4, "matchmaking.MATCHFRAMEWORK_001");
    g_interfaces.emplace(0x61C6C730, "engine.GameServerData001");
    g_interfaces.emplace(0x5F782AC8, "materialsystem.VMaterialSystem080");
    g_interfaces.emplace(0x6E4AFFA8, "filesystem_stdio.VFileSystem017");
    g_interfaces.emplace(0x61A0D5C8, "engine.VModelInfoServer002");
    g_interfaces.emplace(0x5BF1AC58, "client.VClient018");
    g_interfaces.emplace(0x5D3FC098, "panorama.PanoramaUIEngine001");
    g_interfaces.emplace(0x57F2160C, "client.GameConsole004");
    g_interfaces.emplace(0x745CD310, "vstdlib.VEngineCvar007");
    g_interfaces.emplace(0x5F1547D4, "vguimatsurface.SchemeSurface001");
    g_interfaces.emplace(0x5C35FBC0, "client.RenderToRTHelper001");
    g_interfaces.emplace(0x6C8A4F1C, "datacache.VStudioDataCache005");
    g_interfaces.emplace(0x57F21774, "client.RunGameEngine005");
    g_interfaces.emplace(0x6E335388, "inputsystem.InputSystemVersion001");
}

const std::unordered_map<uint32_t, std::string>& get_interfaces()
{
    return g_interfaces;
}