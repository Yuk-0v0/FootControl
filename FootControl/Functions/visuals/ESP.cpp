#include "ESP.h"
#include "../../Games/EntityManager.h"
#include "../../themes/Themes.h"
#include "../Settings/Settings.h"
namespace cheat {
	static void DrawESP();
	auto red = ImColor(255, 0, 0);      // 红
	auto orange = ImColor(255, 165, 0);    // 橙
	auto yellow = ImColor(255, 255, 0);     // 黄
	auto green = ImColor(0, 255, 0);    // 绿
	auto blue = ImColor(0, 0, 255);      // 蓝
	auto qing = ImColor(0, 255, 255);     // qing
	auto purple = ImColor(148, 0, 211);     // 紫
	auto white = ImColor(255, 255, 255);    // bai
	auto deeppink = ImColor(255, 20, 147); //深粉色
	auto pink = ImColor(255, 192, 203);//粉色se
	auto black = ImColor(0, 0, 0);
	auto gray = ImColor(128, 128, 128);

	static std::string getPrefixBeforeLastUnderscore(const std::string& input);



	ESP::ESP() {
		f_Enabled = config::getValue("functions:ESP", "enabled", false);
		f_Range = config::getValue("functions:ESP", "range", 100.0f);
		f_ShowDis = config::getValue("functions:ESP", "showDis", true);
		f_ShowName = config::getValue("functions:ESP", "showName", true);
		f_Hotkey = Hotkey("functions:ESP");

		f_ShowItem = config::getValue("functions:ESP", "showItem", true);
		f_ShowMonster = config::getValue("functions:ESP", "showMonster", true);
		f_ShowNPC = config::getValue("functions:ESP", "showNPC", true);
		f_ShowPlayer = config::getValue("functions:ESP", "showPlayer", true);

		f_ShowDebug = config::getValue("functions:ESP", "showDebug", false);


	}

	ESP& ESP::getInstance() {
		static ESP instance;
		return instance;
	}

	void ESP::GUI() {
		if (ConfigCheckbox(_("ESP"), f_Enabled, _(""))) {
			ImGui::Indent();
			//f_Hotkey.Draw();
			ConfigDragFloat(_("ESP Range"), f_Range, 1.0f, 1.0f, 500.0f, _("ESP Range"));
			ConfigCheckbox(_("Show Distance"), f_ShowDis, _("Show Distance"));
			ConfigCheckbox(_("Show Name"), f_ShowName, _("Show Name"));

			ImGui::SeparatorText(_("Type"));
			ConfigCheckbox(_("Monster"), f_ShowMonster, "");
			ImGui::SameLine();
			ConfigCheckbox(_("NPC"), f_ShowNPC, "");
			ImGui::SameLine();
			ConfigCheckbox(_("Player"), f_ShowPlayer, "");
			ImGui::SameLine();
			ConfigCheckbox(_("Item"), f_ShowItem, "");

			ConfigCheckbox(_("Debug"), f_ShowDebug, "");

			ImGui::Unindent();
		}
	}

	void ESP::Outer() {

		if (f_Enabled && IsInWorld) {
			DrawESP();
		}
	}

	void ESP::Status() {
		if (f_Enabled)
			ImGui::Text(_("ESP"));
	}

	std::string ESP::getModule() {
		return _("ESP");
	}

	void DrawESP() {
		auto& ESP = ESP::getInstance();
		if (!ESP.f_Enabled) return;

		auto entitylist = cheat::GetAllEntity();
		if (entitylist.empty()) return;

		auto screenWidth = app::Screen_get_width(nullptr);
		auto screenHeight = app::Screen_get_height(nullptr);
		auto playerPos = app::GameUtil_get_playerPos();
		//ObjectType__Enum_Invalid = 0x00000001,
		//    ObjectType__Enum_Character = 0x00000008,
		//    ObjectType__Enum_Enemy = 0x00000010,
		//    ObjectType__Enum_Interactive = 0x00000020,
		//    ObjectType__Enum_Projectile = 0x00000040,
		//    ObjectType__Enum_FactoryRegion = 0x00000080,
		//    ObjectType__Enum_Npc = 0x00000100,
		//    ObjectType__Enum_AbilityEntity = 0x00000200,
		//    ObjectType__Enum_CinematicEntity = 0x00000400,
		//    ObjectType__Enum_RemoteFactoryEntity = 0x00000800,
		//    ObjectType__Enum_Creature = 0x00001000,
		std::unordered_map<app::ObjectType__Enum, std::pair<bool, ImColor>> typeSettings = {
{app::ObjectType__Enum::ObjectType__Enum_Character, {ESP.f_ShowPlayer.getValue(),green}},
{app::ObjectType__Enum::ObjectType__Enum_Enemy, {ESP.f_ShowMonster.getValue(), red}},
{app::ObjectType__Enum::ObjectType__Enum_Npc, {ESP.f_ShowNPC.getValue(), white}},
{app::ObjectType__Enum::ObjectType__Enum_Interactive, {ESP.f_ShowItem.getValue(), yellow}}
		};
		for (cheat::Entity& entity : entitylist) {
			auto type = entity.getObjectType();
			auto drawcolor = white;

			auto it = typeSettings.find(type);
			if (it != typeSettings.end()) {
				const auto& [isEnabled, color] = it->second;
				drawcolor = color;
				if (!isEnabled && !ESP.f_ShowDebug.getValue()) continue;
			}else if (!ESP.f_ShowDebug.getValue()) {
				continue;
				}
				
				app::Vector3 pos = entity.getPosition();
				float distance = app::Vector3_Distance(playerPos, pos, nullptr);

				if (distance > ESP.f_Range.getValue()) continue;

				app::Vector3 rect = app::Camera_WorldToScreenPoint_1(app::Camera_get_main(nullptr), pos, nullptr);

				// 确保对象在摄像机前方
				if (rect.z < 0.1f) continue;

				std::string showtext = "";
				std::string name = entity.getName();
				if (ESP.f_ShowName.getValue()) {
					if (!showtext.empty()) showtext += " | ";
					std::string rname = TRRawName(getPrefixBeforeLastUnderscore(name));
					if (rname.empty())
						rname= TRRawName(name);
					if (!rname.empty())
						showtext += rname;
					else  if(!ESP.f_ShowDebug.getValue())
						continue;
				}

                if (ESP.f_ShowDebug.getValue()) {
					if (!showtext.empty()) showtext += " | ";
					showtext += name;
				}


				if (ESP.f_ShowDis.getValue()) {
					if (!showtext.empty()) showtext += " | ";
					showtext += std::to_string((int)distance) + "m";
				}

				// 修正 ImGui 坐标
				ImVec2 imguiPos(rect.x, screenHeight - rect.y);

				// 绘制文字
				ImGui::PushFont(ImGui::GetIO().Fonts->Fonts[fontindex_menu]);
				ImGui::GetForegroundDrawList()->AddText(nullptr, 18.0f, imguiPos, drawcolor, showtext.c_str());
				ImGui::PopFont();

				// 绘制连线
				ImGui::GetForegroundDrawList()->AddLine(ImVec2(screenWidth / 2, 0), imguiPos, drawcolor, 1.0f);
			}
		
	}
	std::string getPrefixBeforeLastUnderscore(const std::string& input) {
		size_t lastUnderscorePos = input.find_last_of('_'); // Find the position of the last '_'

		if (lastUnderscorePos != std::string::npos) {
			return input.substr(0, lastUnderscorePos); // Extract the substring before the last '_'
		}
		else {
			return input; // If no '_' is found, return the whole string
		}
	}

}
