#include "Debug.h"
//#include "../../api/json/json.hpp"
//using json = nlohmann::json;
#include "../../Games/EntityManager.h"
namespace cheat {
	float tpx;
	float tpy;
	float tpz;
	int32_t mapid;
	static void EventSystem_RaycastAll_Hook(void/*EventSystem*/* __this, void  /*PointerEventData*/* eventData, app::List_1_UnityEngine_EventSystems_RaycastResult_* raycastResults, app::MethodInfo* method);
	//DO_APP_FUNC(0x0C71CA40, app::String*, TMP_Text_get_text, (void/*TMP_Text*/* __this, MethodInfo* method));
	//DO_APP_FUNC(0x0C71CB20, void, TMP_Text_set_text, (void/*TMP_Text*/* __this, app::String* value, MethodInfo* method));


	static app::String* I18nUtils_GetText_1_Hook (void*/*I18nText */text, app::MethodInfo* method);
	Debug::Debug() {
		//f_Enabled = config::getValue("functions:Debug", "enabled", false);

		f_Resolution = Hotkey("functions:Debug:SetResolution");
		f_Resolutionwidth = config::getValue("functions:Debug:Resolution", "widthvalue", 1600);
		f_Resolutionheight = config::getValue("functions:Debug:Resolution", "heightvalue", 900);
		f_Resolutionfullscreen = config::getValue("functions:Debug:Resolution", "fullscreenvalue", false);
		f_UIInspector = config::getValue("functions:Debug", "UIInspector", false);
		f_Proxy = config::getValue("functions:Debug", "Proxy", false);
		f_Proxyhost = config::getValue<std::string>("functions:Debug", "Proxyhost", "");
		HookManager::install(app::EventSystem_RaycastAll, EventSystem_RaycastAll_Hook);// 获取鼠标下组件

        //HookManager::install(app::I18nUtils_GetText_1, I18nUtils_GetText_1_Hook);




	}

	Debug& Debug::getInstance() {
		static Debug instance;
		return instance;
	}

	void Debug::GUI() {
		ImGui::SeparatorText(_("Debug"));
		//	if (BeginGroupPanel("Screen", true)) {
		if (ImGui::Button("SetResolution"))
			SetResolution();
		ImGui::SameLine();
		f_Resolution.Draw();
		ConfigInputInt(_("Screen width"), f_Resolutionwidth, _("RESOLUTION_WIDTH_DESCRIPTION"));
		ConfigInputInt(_("Screen height"), f_Resolutionheight, _("RESOLUTION_HEIGHT_DESCRIPTION"));
		ConfigCheckbox(_("Fullscreen"), f_Resolutionfullscreen, _("Fullscreen"));
		//	}EndGroupPanel();
		//	if (BeginGroupPanel("Proxy", true)) {
		ConfigCheckbox(_("Proxy"), f_Proxy, _("Proxy"));
		ConfigInputText(_("Proxy host"), f_Proxyhost, _("connect to ps, e.g : 127.0.0.1:5000 "));
		//	}EndGroupPanel();

			//if (BeginGroupPanel("Teleport", true)) {
		if (cheat::IsInWorld) {
			auto pos = app::GameUtil_get_playerPos();
			ImGui::Text("PlayerPos (%f,%f,%f)", pos.x, pos.y, pos.z);
		}

		ImGui::Separator();
		if (ImGui::Button("tp")) {
			Tpto(app::Vector3(tpx, tpy, tpz));
		}
		ImGui::SameLine();
		if (ImGui::Button("tp by map")) {
			NetTpto(app::Vector3(tpx, tpy, tpz), mapid);
		}
		ImGui::InputFloat("x", &tpx);
		ImGui::InputFloat("y", &tpy);
		ImGui::InputFloat("z", &tpz);
		ImGui::InputInt("MapId", &mapid);
		//}
		//EndGroupPanel();
		ConfigCheckbox(_("Mouse UI in Inspector"), f_UIInspector, _("Mouse UI in Inspector"));
		if (ImGui::Button("find level objs")) {


		}
	}


	void Debug::Outer() {
		//if (f_Hotkey.IsPressed())
		//	f_Enabled.setValue(!f_Enabled.getValue());
		if (f_Resolution.IsPressed())
			SetResolution();


	}



	void Debug::Status() {
		//if (f_Enabled.getValue())
		//	ImGui::Text(_("Debug"));
	}

	std::string Debug::getModule() {
		return "Debug";
	}



	void Debug::SetResolution() {
		if (f_Resolutionwidth.getValue() != 0 && f_Resolutionheight.getValue() != 0)
		{
			app::Screen_SetResolution(f_Resolutionwidth.getValue(), f_Resolutionheight.getValue(), f_Resolutionfullscreen.getValue(), nullptr);

		}

		LOG_INFO("SetResolution to %d x %d, fullscreen: %s", f_Resolutionwidth.getValue(), f_Resolutionheight.getValue(), f_Resolutionfullscreen.getValue() ? "true" : "false");

	}
	void EventSystem_RaycastAll_Hook(void/*EventSystem*/* __this, void  /*PointerEventData*/* eventData, app::List_1_UnityEngine_EventSystems_RaycastResult_* raycastResults, app::MethodInfo* method) {

		CALL_ORIGIN(EventSystem_RaycastAll_Hook, __this, eventData, raycastResults, method);
		auto& Debug = Debug::getInstance();
		if (Debug.f_UIInspector.getValue()) {
			auto  items = raycastResults->fields._items;
			auto count = raycastResults->fields._size;

			for (int i = 0; i < count; i++) {
				auto& raycastResult = items->vector[i];
				auto a = reinterpret_cast<app::Object_1*>(raycastResult.m_GameObject);
				LOG_DEBUG("OBJ: %s childcount:%d", il2cppi_to_string(app::Object_1_get_name(a, nullptr)).c_str(), app::Transform_GetChildCount(app::GameObject_get_transform(raycastResult.m_GameObject, nullptr), nullptr));
			}
		}

	}

	//app::String* I18nUtils_GetText_Hook(app::String* key, app::MethodInfo* method) {
	//
	//	auto re = CALL_ORIGIN(I18nUtils_GetText_Hook, key, method);
	//	if (il2cppi_to_string(re) == "余烬")
	//		return string_to_il2cppi("余烬(Gemini-2.0-flash-exp)");
	//	if (il2cppi_to_string(re)=="帝江号的各项功能都很完备，但终究不是战舰……没有常时备战的流程，多少让我有些不习惯。")
	//		return string_to_il2cppi("您好！我是 Google 训练的大型语言模型。我的设计目标是理解和生成人类语言，并以有用的方式回应各种提示和问题。");
	//	if (il2cppi_to_string(re) == "有空和我过两招怎么样？——当然了，别让佩丽卡知道！")
	//		return string_to_il2cppi("您好！我是 Google 训练的大型语言模型。我的设计目标是理解和生成人类语言，并以有用的方式回应各种提示和问题。");
	//	return re;
	//
	//}
	app::String* I18nUtils_GetText_1_Hook(void*/*I18nText */text, app::MethodInfo* method) {
		auto re = CALL_ORIGIN(I18nUtils_GetText_1_Hook, text, method);
		//LOG_DEBUG("I18nUtils_GetText_1_Hook %s", il2cppi_to_string(re).c_str());

		if (il2cppi_to_string(re) == "陈千语")
			return string_to_il2cppi("陈千语(Gemini-2.0-flash-exp)");


		return re;
	}


}