#include "pch-il2cpp.h"
#include "_hooks.h"
#include "logger.h"
#include "state.hpp"

/*void fakeSuccessfulLogin(EOSManager* eosManager)
{
	eosManager->fields.loginFlowFinished = true;
	EOSManager_HasFinishedLoginFlow(eosManager, NULL);
}*/

void dEOSManager_LoginFromAccountTab(EOSManager* __this, MethodInfo* method)
{
	//EOSManager_DeleteDeviceID(__this, NULL);
	EOSManager_LoginFromAccountTab(__this, method);
	//LOG_DEBUG("Faking login");
	//fakeSuccessfulLogin(__this);
}

void dEOSManager_InitializePlatformInterface(EOSManager* __this, MethodInfo* method)
{
	EOSManager_InitializePlatformInterface(__this, method);
	//LOG_DEBUG("Skipping device identification");
	//__this->fields.platformInitialized = true;
}

bool dEOSManager_IsFreechatAllowed(EOSManager* __this, MethodInfo* method)
{
	return app::EOSManager_IsFreechatAllowed(__this, method);
}

bool dEOSManager_IsFriendsListAllowed(EOSManager* __this, MethodInfo* method)
{
	return app::EOSManager_IsFriendsListAllowed(__this, method);
}

void dEOSManager_UpdatePermissionKeys(EOSManager* __this, void* callback, MethodInfo* method) {
	Il2CppClass* klass = get_class("Assembly-CSharp, EOSManager");
	LOG_ASSERT(klass);
	FieldInfo* field = il2cpp_class_get_field_from_name(klass, "isKWSMinor");
	LOG_ASSERT(field);
	bool value = false;
	il2cpp_field_set_value((Il2CppObject*)__this, field, &value);

	app::EOSManager_UpdatePermissionKeys(__this, callback, method);
}

void dEOSManager_Update(EOSManager* __this, MethodInfo* method) {
	if (State.SpoofFriendCode) __this->fields.friendCode = convert_to_string(State.FakeFriendCode);
	EOSManager_Update(__this, method);
}

String* dEOSManager_get_ProductUserId(EOSManager* __this, MethodInfo* method) {
	if (State.SpoofPuid && State.FakePuid != "") return convert_to_string(State.FakePuid);
	return EOSManager_get_ProductUserId(__this, method);
}