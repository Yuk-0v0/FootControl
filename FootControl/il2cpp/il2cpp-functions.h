#include "il2cpp-types.h"
//#include "il2cpp-enum.h"


using namespace app;


//globalupdate
//UnityEngine.EventSystems.EventSystem$$Update
//DO_APP_FUNC(0x024E4CF0,  void, EventSystem_Update, ( app::EventSystem* __this, app::MethodInfo* method));
DO_APP_FUNC(0x03373CB0, void, GameApp_Update, (void* __this));
DO_APP_FUNC(0x033736D0, void/*GameApp*/*, GameApp_get_instance, ());
DO_APP_FUNC(0x033737A0, app::GameState__Enum, GameApp_get_currentState, (void/*GameApp*/* __this, app::MethodInfo* method));
DO_APP_FUNC(0x0337A7F0, void, GameStartState__OnEnterMainGame, (void/*GameStartState*/* __this, MethodInfo* method));

DO_APP_FUNC(0x0CB84EF0, void, EventSystem_RaycastAll, (void/*EventSystem*/* __this, void  /*PointerEventData*/* eventData, app::List_1_UnityEngine_EventSystems_RaycastResult_* raycastResults, app::MethodInfo* method));

//damage

DO_APP_FUNC(0x07C5C1E0, void/*app::BattleNormalEffect*/*, EffectManager_CreateEffectOnTarget, (void/*EffectManager*/* __this, void/*EffectActionCfg*/* effectCfg, void/*app::AbilitySystem*/* target, app::Vector3 dir, void/*ITickOwner*/* timeScaleSource, app::String* overrideName,void /*app::AbilitySystem*/* source));

//DO_APP_FUNC(0x07061FB0, bool, BattleHitReactionManager_TryGetHitInfo, (BattleHitReactionManager* __this, ECSColliderResultProxy collider, Vector3 hitPoint, BattleHitReactionManager_HitInfo* hitInfo, app::MethodInfo* method));

DO_APP_FUNC(0x083DAAD0, app::AbilitySystem_Modifier, AbilitySystem_Modifier_NewDamage, (void /*AbilitySystem*/* source, void /*AbilitySystem*/* target, double value, app::DamageType__Enum damageType, app::DamageDecorateMask__Enum damageDecorateMask, app::AbilitySystem_Modifier_DamageVisualImportance__Enum damageVisualImportance, bool isCritical, app::String* damageSourceId, void/*AbilitySystem_Modifier_DamageVisualCoalition*/* damageVisualCoalition, app::Nullable_1_UnityEngine_Vector3_ hitPoint, bool hideMainCharHpScreenEffect, app::MethodInfo* method));
//DO_APP_FUNC(0x083DAA30, AbilitySystem_Modifier, AbilitySystem_Modifier_NewDamage_1, (AbilitySystem* source, AbilitySystem* target, double value, DamageType__Enum damageType, DamageDecorateMask__Enum damageDecorateMask, AbilitySystem_Modifier_DamageVisualImportance__Enum damageVisualImportance, bool isCritical, app::MethodInfo* method));
//DO_APP_FUNC(0x083DAC20, AbilitySystem_Modifier, AbilitySystem_Modifier_NewHeal, (AbilitySystem* source, AbilitySystem* target, double value, bool showText, app::MethodInfo* method));
//DO_APP_FUNC(0x083DAD30, AbilitySystem_Modifier, AbilitySystem_Modifier_NewHeal_1, (AbilitySystem* source, AbilitySystem* target, double value, bool showText, bool createBuff, app::MethodInfo* method));
//DO_APP_FUNC(0x07062390, void, BattleHitReactionManager_Hit, (void/*BattleHitReactionManager*/* __this, app::Entity* attacker, app::String* hitMethodId, float hitValue, bool dontHitImportantInteractive, app::BattleHitReactionManager_HitInfo hitInfo, app::MethodInfo* method));

//entity
DO_APP_FUNC(0x07A01350, GameWorld*, GameInstance_get_world, ());
//DO_APP_FUNC(0x07404B50, void, SceneGridContext_GetEntityList, (void/*SceneGridContext*/* __this, Vector3 pos, float radius, EEntityType__Enum entityType, List_1_Beyond_ObjectPtr_1__4* target, app::MethodInfo* method));
DO_APP_FUNC(0x07201880, UnorderedArray_1_ObjectPtr_1_Beyond_Gameplay_Core_Entity_*, GameWorld_get_allEntities, (GameWorld* __this, app::MethodInfo* method));
DO_APP_FUNC(0x072018E0, UnorderedArray_1_ObjectPtr_1_Beyond_Gameplay_Core_Entity_*, GameWorld_get_allCharacters, (GameWorld* __this, app::MethodInfo* method));
DO_APP_FUNC(0x07201940, UnorderedArray_1_ObjectPtr_1_Beyond_Gameplay_Core_Entity_*, GameWorld_get_allInteractives, (GameWorld*, app::MethodInfo* method));
DO_APP_FUNC(0x072019A0, UnorderedArray_1_ObjectPtr_1_Beyond_Gameplay_Core_Entity_*, GameWorld_get_allEnemies, (GameWorld*, app::MethodInfo* method));


DO_APP_FUNC(0x08376610, Camera*, GameUtil_get_mainCamera, ());
DO_APP_FUNC(0x083766A0, app::Entity*, GameUtil_get_mainCharacter, ());
DO_APP_FUNC(0x08376730, Transform*, GameUtil_get_playerTrans, ());
DO_APP_FUNC(0x083767D0, app::Vector3, GameUtil_get_playerPos, ());

DO_APP_FUNC(0x083E3740, float, AbilitySystemUtils_GetDistance_3, (app::Entity* source, app::Entity* target, app::MethodInfo* method));
DO_APP_FUNC(0x083E2A30, Vector3, AbilitySystemUtils_GetPosition, (void*/*AbilitySystem*/* source, app::MethodInfo* method));
DO_APP_FUNC(0x083AD220, app::ObjectType__Enum, AbilitySystem_get_objectType, (void /*AbilitySystem*/* __this, app::MethodInfo* method));


DO_APP_FUNC(0x00C7E650, app::String*, Entity_get_name, (app::Entity* __this, app::MethodInfo* method));
DO_APP_FUNC(0x00C8BCD0, uint32_t, Entity_get_instanceUid, (app::Entity* __this, app::MethodInfo* method));
DO_APP_FUNC(0x06691F10, app::ObjectType__Enum, Entity_get_objectType, (app::Entity* __this, app::MethodInfo* method));
DO_APP_FUNC(0x07357400, app::Vector3, Entity_get_position, (app::Entity* __this, app::MethodInfo* method));
DO_APP_FUNC(0x07361180, void/*AbilitySystem*/*, Entity_get_abilityCom, (Entity* __this, MethodInfo* method));

DO_APP_FUNC(0x07360E60, void/*ActorController*/*, Entity_get_actorCtrl, (app::Entity* __this, app::MethodInfo* method));
DO_APP_FUNC(0x073419A0, int32_t, ActorController_MoveTo, (void/*ActorController*/* __this, Vector3 targetPosition, bool ignoreUnmovable, app::MethodInfo* method));
DO_APP_FUNC(0x07343640, void, ActorController_TeleportToTempFix, (void/*ActorController*/* __this, Vector3 inPos, app::MethodInfo* method));

//pickup
//DO_APP_FUNC(0x07F3F2F0, bool, InteractiveInstigatorControlComponent_SetPickupItem, (InteractiveInstigatorControlComponent* __this, Entity* item, bool ignoreSkillCheck, bool ignoreCheck, /*Nullable_1_UnityEngine_Vector3_*/app::Vector3 sourcePos, app::MethodInfo* method));

//DO_APP_FUNC(0x07F3FB20, void, InteractiveInstigatorControlComponent_PickUp, (InteractiveInstigatorControlComponent* __this, app::MethodInfo* method));




//killaura
DO_APP_FUNC(0x072054F0, void, GameWorld_KillAllEnemies, (GameWorld* __this, app::MethodInfo* method));
DO_APP_FUNC(0x07206620, void, GameWorld_HealAllCharacters, (GameWorld* __this, app::MethodInfo* method));
//skill
//DO_APP_FUNC(0x0839EDA0, float, Skill_get_cooldown, (Skill* __this, app::MethodInfo* method));
DO_APP_FUNC(0x083A3540, bool, Skill_CheckCd, (void/*Skill*/* __this, app::MethodInfo* method));
DO_APP_FUNC(0x083A38C0, bool, Skill_CheckCost, (void/*Skill*/* __this, app::MethodInfo* method));
//DO_APP_FUNC(0x00C8BCD0, int32_t, SC_SYNC_ULTIMATE_SP_CELL_CNT_get_UltimateSpCellCnt, (void/*SC_SYNC_ULTIMATE_SP_CELL_CNT*/* __this, MethodInfo* method));
DO_APP_FUNC(0x083ADD40, float, AbilitySystem_get_ultimateSp, (void/*AbilitySystem*/* __this, MethodInfo* method));


//skip plot
DO_APP_FUNC(0x070C8220, void, DialogManager__DoPlayDialog, (void/*DialogManager*/* __this, app::MethodInfo* method));
DO_APP_FUNC(0x070CA350 ,void, DialogManager__ExitDialog, (void/*DialogManager*/* __this, bool isSkip, app::MethodInfo* method));
DO_APP_FUNC(0x0BBBA990, void, Cutscene_Skip, (void/*Cutscene*/* __this, MethodInfo* method));
DO_APP_FUNC(0x0BBBA9A0, void, Cutscene_SkipCurrentSection, (void/*Cutscene*/* __this, MethodInfo* method));

//stamina

//DO_APP_FUNC(0x00BF5EF0, uint32_t, SC_SYNC_STAMINA_get_CurStamina, (app::SC_SYNC_STAMINA* __this, app::MethodInfo* method));
//DO_APP_FUNC(0x017F6020, CharCurStamina*, Beyond_Gameplay_CharCurStaminaForMemoryPack_GetValue, (Beyond_Gameplay_CharCurStaminaForMemoryPack* __this, app::MethodInfo* method));
//DO_APP_FUNC(0x06E5E620, float, PlayerController_get_maxDashCount, (void/*PlayerController*/* __this, app::MethodInfo* method));
//DO_APP_FUNC(0x06C055A0, int32_t, GlobalConst_get_dashCostEnergyValue, (void/*GlobalConst*/* __this, app::MethodInfo* method));
 DO_APP_FUNC(0x06C267F0, int32_t, Tables_GlobalConst_get_dashCostEnergyValue, (void/*Tables_GlobalConst*/ * __this, app::MethodInfo * method));
//monsterAI

DO_APP_FUNC(0x0812C420, void, EnemyAIBrain_SwitchAIMode, (void/*EnemyAIBrain*/* __this, app::EnemyAIModeType__Enum modeType, bool force, app::MethodInfo* method));


//dither

DO_APP_FUNC(0x082BA5B0, void, EntityRenderHelper_SetDitherAlpha, (void/*EntityRenderHelper*/* __this, float ditherAlpha, int32_t handle, app::MethodInfo* method));

//tp

DO_APP_FUNC(0x08378D50, app::String*, GameUtil_GetCntLevelId, ());
DO_APP_FUNC(0x08378670, int32_t, GameUtil_LevelIdStringToNum, (app::String* levelIdStr));

DO_APP_FUNC(0x07A01850, void/*GameplayNetwork*/*, GameInstance_get_gameplayNetwork, ());
DO_APP_FUNC(0x07B6F720, void, GameplayNetwork_C2STeleport, (void/*GameplayNetwork*/* __this, int32_t levelId, app::TeleportReason__Enum reason, app::Vector3 position, app::Vector3 rotationEuler, app::MethodInfo* method));

//DO_APP_FUNC(0x071FD4E0, app::FunctionAreaManager*, GameWorld_get_functionAreaManager, (app::GameWorld* __this,app:: MethodInfo* method));
DO_APP_FUNC(0x07F65CD0, void, GameAction_TeleportTeam, (app::Vector3 position, app::Vector3 rotation, app::MethodInfo* method));
//DO_APP_FUNC(0x07F67270, void, GameAction_TeleportTo, (app::String* levelIdStr, app::TeleportReason__Enum reason, app::Vector3 position, app::Vector3 rotationEuler, app::MethodInfo* method));
//DO_APP_FUNC(0x07F67710, void, GameAction_TeleportToPosition, (app::String* sceneId, app::TeleportReason__Enum reason, app::Vector3 pos, app::Quaternion rotation, app::MethodInfo* method));
 DO_APP_FUNC(0x01FA8AE0, app::Vector3, Beyond_Gameplay_PosTrackingInfoForMemoryPack_get___trackingPos__, (void/*Beyond_Gameplay_PosTrackingInfoForMemoryPack*/ * __this, MethodInfo * method));
//DO_APP_FUNC(0x070F2360, void, CharacterController_1_TeleportToWithFx, (CharacterController_1* __this, Vector3 pos, bool playBlinkFx, bool playDissolveFx, app::MethodInfo* method));
// 
//custom Profile

DO_APP_FUNC(0x036F4860, app::String*, UtilsForLua_GetCurrentUID, ());
DO_APP_FUNC(0x0C724180, app::String*, TMP_Text_get_text, (void/*TMP_Text*/* __this, MethodInfo* method));
DO_APP_FUNC(0x0C724260, void, TMP_Text_set_text, (void/*TMP_Text*/* __this, app::String* value, MethodInfo* method));



//System.Runtime.InteropServices.Marshal$$PtrToStringAnsi

DO_APP_FUNC(0x0B2D79B0, app::String*, Marshal_PtrToStringAnsi, (void* ptr, app::MethodInfo* method));
DO_APP_FUNC(0x06DC8EB0, app::String*, I18nUtils_GetText, (app::String* key, app::MethodInfo* method));
DO_APP_FUNC(0x06DC92E0, app::String*, I18nUtils_GetText_1, (void*/*I18nText */text, app::MethodInfo* method));
//DO_APP_FUNC(0x06DC8F70, bool, I18nUtils_TryGetText, (app::String* key, app::String** value, app::MethodInfo* method));
//DO_APP_FUNC(0x06DE3C10, app::String *, DialogTextData_get_dialogText, (void/*DialogTextData*/ * __this, app::MethodInfo * method));
//playerspeed
// 

//DO_APP_FUNC(0x072BE5E0, app::Vector3, MovementComponent_get_velocity, (void/*MovementComponent*/* __this, MethodInfo* method));
//DO_APP_FUNC(0x072BE670, float, MovementComponent_get_speed, (void/*MovementComponent*/* __this, MethodInfo* method));
DO_APP_FUNC(0x0735E2A0, void/*SelfTimeScaleHandle*/*, Entity_SetSelfTimeScale, (app::Entity* __this, float selfTimeScale, app::MethodInfo* method));
//DO_APP_FUNC(0x0C926250, void, Rigidbody_set_velocity, (void/*Rigidbody*/* __this, app::Vector3 value, MethodInfo* method));
DO_APP_FUNC(0x0C92D920, app::Vector3, Rigidbody_get_velocity, (void/*Rigidbody*/* __this, MethodInfo* method));
//DO_APP_FUNC(0x0C8093B0, float, Animator_get_timeScale, (Animator* __this, app::MethodInfo* method));
//DO_APP_FUNC(0x0C809400, void, Animator_set_timeScale, (Animator* __this, float value, app::MethodInfo* method));
//DO_APP_FUNC(0x0C809460, float, Animator_get_speed, (Animator* __this, app::MethodInfo* method));
//DO_APP_FUNC(0x0C8094B0, void, Animator_set_speed, (Animator* __this, float value, app::MethodInfo* method));

// Game Object, Transform, Object, Component Utility

//public sealed class GameObject :
//UnityEngine.GameObject$$CreatePrimitive
DO_APP_FUNC(0x0C8864D0, GameObject*, GameObject_CreatePrimitive, (PrimitiveType__Enum type, app::MethodInfo* method));
//UnityEngine.GameObject$$get_active
DO_APP_FUNC(0x0C887350, bool, GameObject_get_active, (GameObject* __this, app::MethodInfo* method));
//UnityEngine.GameObject$$SetActive
DO_APP_FUNC(0x0C887400, void, GameObject_SetActive, (GameObject* __this, bool value, app::MethodInfo* method));//UnityEngine.GameObject$$Find
DO_APP_FUNC(0x0C887EA0, GameObject*, GameObject_Find, (String* name, app::MethodInfo* method));

DO_APP_FUNC(0x0C886660, Component*, GameObject_GetComponentByName, (GameObject* __this, String* type, app::MethodInfo* method));
//UnityEngine.GameObject$$GetComponentByName
DO_APP_FUNC(0x0C8870E0, Component*, GameObject_AddComponentInternal, (GameObject* __this, String* className, app::MethodInfo* method));
//UnityEngine.GameObject$$AddComponentInternal

//UnityEngine.GameObject$$get_transform
DO_APP_FUNC(0x0C8871A0, Transform*, GameObject_get_transform, (GameObject* __this, app::MethodInfo* method));

DO_APP_FUNC(0x0C88D8F0, app::Object_1__Array*, Object_1_FindObjectsOfType, (app::Type* type, MethodInfo* method));


DO_APP_FUNC(0x0C89B320, Transform*, Transform_GetChild, (Transform* __this, int32_t index, app::MethodInfo* method));
//UnityEngine.Transform$$GetChild

DO_APP_FUNC(0x0C89B380, int32_t, Transform_GetChildCount, (Transform* __this, app::MethodInfo* method));
//UnityEngine.Transform$$GetChildCount

//UnityEngine.Transform$$FindChild
DO_APP_FUNC(0x0C89AF10, Transform*, Transform_FindChild, (Transform* __this, String* n, app::MethodInfo* method));

DO_APP_FUNC(0x0C89B6F0, void, Transform_set_localPosition, (Transform * __this, app::Vector3 value, MethodInfo * method));
DO_APP_FUNC(0x0C897550, app::Vector3, Transform_get_localPosition, (Transform* __this, app::MethodInfo* method));

DO_APP_FUNC(0x0C898680, void, Transform_set_localRotation, (Transform* __this, Quaternion value, app::MethodInfo* method));
DO_APP_FUNC(0x0C898610, Quaternion, Transform_get_localRotation, (Transform* __this, app::MethodInfo* method));



DO_APP_FUNC(0x0C898790, Vector3, Transform_get_localScale, (Transform * __this, MethodInfo * method));
DO_APP_FUNC(0x0C898800, void, Transform_set_localScale, (Transform * __this, Vector3 value, MethodInfo * method));

DO_APP_FUNC(0x0C897A90, Vector3, Transform_get_right, (Transform * __this, MethodInfo * method));
DO_APP_FUNC(0x0C897E20, Vector3, Transform_get_up, (Transform * __this, MethodInfo * method));
DO_APP_FUNC(0x0C8981B0, Vector3, Transform_get_forward, (Transform * __this, MethodInfo * method));

DO_APP_FUNC(0x0C897480, Vector3, Transform_get_position, (Transform * __this, MethodInfo * method));
DO_APP_FUNC(0x0C8974F0, void, Transform_set_position, (Transform * __this, Vector3 value, MethodInfo * method));

DO_APP_FUNC(0x0C898540, app::Quaternion, Transform_get_rotation, (Transform * __this, MethodInfo * method));
DO_APP_FUNC(0x0C8985B0, void, Transform_set_rotation, (Transform * __this, app::Quaternion value, MethodInfo * method));

DO_APP_FUNC(0x0C898860, Transform *, Transform_get_parent, (Transform * __this, MethodInfo * method));
DO_APP_FUNC(0x0C8988B0, void, Transform_set_parent, (Transform * __this, Transform * value, MethodInfo * method));

DO_APP_FUNC(0x0C897770, Vector3, Transform_get_eulerAngles, (Transform * __this, MethodInfo * method));
DO_APP_FUNC(0x0C897810, void, Transform_set_eulerAngles, (Transform * __this, Vector3 value, MethodInfo * method));

DO_APP_FUNC(0x0C897900, Vector3, Transform_get_localEulerAngles, (Transform * __this, MethodInfo * method));
DO_APP_FUNC(0x0C8979A0, void, Transform_set_localEulerAngles, (Transform * __this, Vector3 value, MethodInfo * method));


DO_APP_FUNC(0x0C898F60, void, Transform_Translate, (app::Transform* __this, app::Vector3 translation));
////UnityEngine.Object$$get_name
DO_APP_FUNC(0x0C88C5E0, String *, Object_1_get_name, (Object_1 * __this, MethodInfo * method));
////UnityEngine.Object$$DestroyImmediate
DO_APP_FUNC(0x0C88D860, void, Object_1_DestroyImmediate_1, (Object_1 * obj, MethodInfo * method));
////UnityEngine.Component$$get_gameObject
DO_APP_FUNC(0x0AEB8EE0, GameObject *, Component_get_gameObject, (Component * __this, MethodInfo * method));
DO_APP_FUNC(0x0C88CB80, Object_1 *, Object_1_Instantiate, (Object_1 * original, Vector3 position, Quaternion rotation, MethodInfo * method));
DO_APP_FUNC(0x0C89AC40, int32_t, Transform_get_childCount, (Transform* __this, app::MethodInfo* method));
//DO_APP_FUNC(0x0C8A0880,void*/* Scene*/, SceneManager_GetActiveScene, (MethodInfo* method));
//DO_APP_FUNC(0x0C89FE30, void, Scene_GetRootGameObjects_1, (void* __this, List_1_UnityEngine_GameObject_* rootGameObjects, app::MethodInfo* method));
// UnityEngine.RenderSettings$$set_fog
DO_APP_FUNC(0x0C850C70, float, RenderSettings_get_fogStartDistance, (MethodInfo* method));
DO_APP_FUNC(0x0C850CC0, void, RenderSettings_set_fogStartDistance, (float value, MethodInfo* method));
DO_APP_FUNC(0x0C850D20, float, RenderSettings_get_fogEndDistance, (MethodInfo* method));
DO_APP_FUNC(0x0C850D70, void, RenderSettings_set_fogEndDistance, (float value, MethodInfo* method));

DO_APP_FUNC(0x0C850E80, float, RenderSettings_get_fogDensity, (MethodInfo* method));
DO_APP_FUNC(0x0C850ED0, void, RenderSettings_set_fogDensity, (float value, MethodInfo* method));

//public static void set_fog(bool value) { }

//public class Time
DO_APP_FUNC(0x0B640A10 ,float, Time_get_deltaTime, (MethodInfo * method));
//public static float get_deltaTime() { }
DO_APP_FUNC(0x0C893590, float, Time_1_get_timeScale, (MethodInfo* method));
DO_APP_FUNC(0x0C8935E0, void, Time_1_set_timeScale, (float value, MethodInfo* method));


DO_APP_FUNC(0x0C4FCE60, bool, Application_get_isFocused, (MethodInfo * method));
//public static bool get_isFocused() { }
DO_APP_FUNC(0x0C82A580, void, Application_set_targetFrameRate, (int32_t value, MethodInfo * method));
//	public static void set_targetFrameRate(int value) { }
DO_APP_FUNC(0x0C849B90, void, QualitySettings_set_vSyncCount, (int32_t value, MethodInfo * method));

//UnityEngine.Vector3$$Distance
DO_APP_FUNC(0x0C87A1C0, float, Vector3_Distance, (Vector3 a, Vector3 b, MethodInfo * method));

DO_APP_FUNC(0x0C879480, Vector3, Vector3_Lerp, (Vector3 a, Vector3 b, float t, MethodInfo * method));


//public class Cursor

DO_APP_FUNC(0x0C873B00, bool, Cursor_get_visible, (MethodInfo * method));
DO_APP_FUNC(0x0C873B50, void, Cursor_set_visible, (bool value, MethodInfo * method));
//public static void set_visible(bool value) { }
DO_APP_FUNC(0x0C873BA0, CursorLockMode__Enum, Cursor_get_lockState, (MethodInfo * method));
//public static CursorLockMode get_lockState() { }
DO_APP_FUNC(0x0C873BF0, void, Cursor_set_lockState, (CursorLockMode__Enum value, MethodInfo * method));
//public static void set_lockState(CursorLockMode value) { }

DO_APP_FUNC(0x0C8439F0, int32_t, Screen_get_width, (MethodInfo* method));
DO_APP_FUNC(0x0C843A40, int32_t, Screen_get_height, (MethodInfo* method));


//public static int get_height() { }
DO_APP_FUNC(0x0C844250, void, Screen_SetResolution, (int32_t width, int32_t height, bool fullscreen, MethodInfo * method));

//camera
DO_APP_FUNC(0x0C832380, void, Camera_CopyFrom, (Camera * __this, Camera * other, MethodInfo * method));
DO_APP_FUNC(0x0C8312D0, Camera *, Camera_get_main, (MethodInfo * method));
DO_APP_FUNC(0x0C831320, Camera *, Camera_get_current, (MethodInfo * method));
DO_APP_FUNC(0x0C82DBB0, float, Camera_get_fieldOfView, (Camera * __this, MethodInfo * method));
DO_APP_FUNC(0x0C82DC00, void, Camera_set_fieldOfView, (Camera * __this, float value, MethodInfo * method));

DO_APP_FUNC(0x0C830550, Vector3, Camera_WorldToScreenPoint_1, (Camera * __this, Vector3 position, MethodInfo * method));


DO_APP_FUNC(0x00BEE9F0, float, Mathf_Lerp, (float a, float b, float t, MethodInfo * method));
DO_APP_FUNC(0x0C87D9F0, float, Mathf_LerpUnclamped, (float a, float b, float t, MethodInfo * method));
DO_APP_FUNC(0x02F52590, float, Mathf_LerpAngle, (float a, float b, float t, MethodInfo * method));
//DO_APP_FUNC(0x0CB82830, float, BaseInput_GetAxisRaw, (BaseInput * __this, String * axisName, MethodInfo * method));
DO_APP_FUNC(0x0C90CBE0, float, Input_1_GetAxis, (String* axisName, app::MethodInfo* method));

//proxy

DO_APP_FUNC(0x0CB97360, app::String*, WebRequestUtils_MakeInitialUrl, (app::String* targetUrl, app::String* localUrl, app::MethodInfo* method));
DO_APP_FUNC(0x0CB9C430, app::String*, UnityWebRequest_get_url, (void/*app::UnityWebRequest*/* __this, MethodInfo* method));
DO_APP_FUNC(0x0B4CE980, void/*UnityWebRequest*/*, HttpSender__CreateWebRequestPOST, (app::String* url,void* /*HttpSender_FPostOptions */options, app::MethodInfo* method));

// Protection bypass


