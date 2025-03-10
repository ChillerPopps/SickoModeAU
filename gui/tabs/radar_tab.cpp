#include "pch-il2cpp.h"
#include "radar_tab.h"
#include "gui-helpers.hpp"
#include "state.hpp"
#include "utility.h"

namespace RadarTab {
	void Render() {
		if (ImGui::BeginTabItem("Radar")) {
			ImGui::Dummy(ImVec2(4, 4) * State.dpiScale);
			if (ImGui::Checkbox("Show Radar", &State.ShowRadar)) {
				State.Save();
			}
			if (State.ShowKeybinds) {
				ImGui::SameLine();
				if (HotKey(State.KeyBinds.Toggle_Radar)) {
					State.Save();
				}
			}

			ImGui::Dummy(ImVec2(7, 7) * State.dpiScale);
			ImGui::Separator();
			ImGui::Dummy(ImVec2(7, 7) * State.dpiScale);

			if (ImGui::Checkbox("Show Dead Bodies", &State.ShowRadar_DeadBodies)) {
				State.Save();
			}
			if (ImGui::Checkbox("Show Ghosts", &State.ShowRadar_Ghosts)) {
				State.Save();
			}
			if (ImGui::Checkbox("Right Click to Teleport", &State.ShowRadar_RightClickTP)) {
				State.Save();
			}

			ImGui::Dummy(ImVec2(7, 7) * State.dpiScale);
			ImGui::Separator();
			ImGui::Dummy(ImVec2(7, 7) * State.dpiScale);

			if (ImGui::Checkbox("Hide Radar During Meetings", &State.HideRadar_During_Meetings)) {
				State.Save();
			}
			if (ImGui::Checkbox("Draw Player Icons", &State.RadarDrawIcons)) {
				State.Save();
			}
			if (State.RadarDrawIcons && State.RevealRoles) {
				ImGui::SameLine();
				if (ImGui::Checkbox("Show Role Color on Visor", &State.RadarVisorRoleColor)) {
					State.Save();
				}
			}

			if (ImGui::Checkbox("Lock Radar Position", &State.LockRadar)) {
				State.Save();
			}
			if (ImGui::Checkbox("Show Border", &State.RadarBorder)) {
				State.Save();
			}
			if (ImGui::ColorEdit4("Radar Color",
				(float*)&State.SelectedColor,
				ImGuiColorEditFlags__OptionsDefault
				| ImGuiColorEditFlags_NoInputs
				| ImGuiColorEditFlags_AlphaBar
				| ImGuiColorEditFlags_AlphaPreview)) {
				State.Save();
			}
			if (ImGui::InputInt("Extra Width", &State.RadarExtraWidth))
				State.Save();
			if (ImGui::InputInt("Extra Height", &State.RadarExtraHeight))
				State.Save();

			ImGui::EndTabItem();
		}
	}
}