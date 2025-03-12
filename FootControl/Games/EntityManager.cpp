#include "EntityManager.h"
#include "../Resources/entity_map.h"
#include "../Functions/Settings/Settings.h"

namespace cheat {

    cheat::Entity GetPlayerEntity() {
        auto p = app::GameUtil_get_mainCharacter();
        if (p == nullptr)
        {
            return cheat::Entity(nullptr);
        }
        return cheat::Entity(p);

    }

    std::vector<cheat::Entity> GetAllEntity()
    {
        auto list = app::GameWorld_get_allEntities(app::GameInstance_get_world(), nullptr);
        std::vector<cheat::Entity> entityList;

        if (!list || !list->fields.m_items) {
            std::cerr << "Invalid input array!" << std::endl;
            return entityList;
        }

        // 获取有效元素的数量
        int count = list->fields._count_k__BackingField;
        auto items = list->fields.m_items;

        // 遍历有效元素并加入到 std::vector
        for (int i = 0; i < count; i++) {
            auto& objectPtr = items->vector[i];
            if (objectPtr.obj) { // 确保 obj 不为 nullptr
                entityList.push_back(cheat::Entity(objectPtr.obj));
            }
        }

        return entityList;

    }


    std::string TRRawName(const std::string& idPrefix) {
        auto& Setttings = cheat::Settings::getInstance();
        int index = Setttings.f_Language.getValue();
        auto it = entityMap.find(idPrefix); // Search for the ID in the map

        if (it != entityMap.end()) {
            if (index == 1) {
                // Return the first value (Chinese name) from the tuple
                return std::get<0>(it->second);
            }
            else if (index == 0) {
                // Return the second value (English name) from the tuple
                return std::get<1>(it->second);
            }
            else {
                return "Invalid index"; // Return an error message for invalid index
            }
        }
        else {
            return ""; // Return "Unknown" if the ID is not found
        }
    }
}