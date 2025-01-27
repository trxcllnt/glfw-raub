#include "platform.hpp"
#include "glfw.hpp"


#define JS_GLFW_CONSTANT(name)                                                \
	exports.Set(#name, static_cast<double>(GLFW_ ## name));

#define JS_GLFW_SET_METHOD(name)                                              \
	exports.DefineProperty(                                                   \
		Napi::PropertyDescriptor::Function(env, exports, #name, glfw::name)   \
	);


Napi::Object initModule(Napi::Env env, Napi::Object exports) {
	
	std::atexit(glfw::deinit);
	
	/* GLFW initialization, termination and version querying */
	JS_GLFW_SET_METHOD(init);
	JS_GLFW_SET_METHOD(terminate);
	JS_GLFW_SET_METHOD(getVersion);
	JS_GLFW_SET_METHOD(getVersionString);
	
	/* Time */
	JS_GLFW_SET_METHOD(getTime);
	JS_GLFW_SET_METHOD(setTime);
	
	/* Monitor handling */
	JS_GLFW_SET_METHOD(getMonitors);
	
	/* Window handling */
	JS_GLFW_SET_METHOD(createWindow);
	JS_GLFW_SET_METHOD(windowHint);
	JS_GLFW_SET_METHOD(defaultWindowHints);
	JS_GLFW_SET_METHOD(platformWindow);
	JS_GLFW_SET_METHOD(platformContext);
	JS_GLFW_SET_METHOD(destroyWindow);
	JS_GLFW_SET_METHOD(setWindowShouldClose);
	JS_GLFW_SET_METHOD(windowShouldClose);
	JS_GLFW_SET_METHOD(setWindowTitle);
	JS_GLFW_SET_METHOD(setWindowIcon);
	JS_GLFW_SET_METHOD(getWindowSize);
	JS_GLFW_SET_METHOD(setWindowSize);
	JS_GLFW_SET_METHOD(setWindowPos);
	JS_GLFW_SET_METHOD(getWindowPos);
	JS_GLFW_SET_METHOD(getFramebufferSize);
	JS_GLFW_SET_METHOD(iconifyWindow);
	JS_GLFW_SET_METHOD(restoreWindow);
	JS_GLFW_SET_METHOD(showWindow);
	JS_GLFW_SET_METHOD(hideWindow);
	JS_GLFW_SET_METHOD(getWindowAttrib);
	JS_GLFW_SET_METHOD(setInputMode);
	JS_GLFW_SET_METHOD(pollEvents);
	JS_GLFW_SET_METHOD(waitEvents);
	
	/* Input handling */
	JS_GLFW_SET_METHOD(getKey);
	JS_GLFW_SET_METHOD(getMouseButton);
	JS_GLFW_SET_METHOD(getCursorPos);
	JS_GLFW_SET_METHOD(setCursorPos);
	
	/* Context handling */
	JS_GLFW_SET_METHOD(makeContextCurrent);
	JS_GLFW_SET_METHOD(getCurrentContext);
	JS_GLFW_SET_METHOD(swapBuffers);
	JS_GLFW_SET_METHOD(swapInterval);
	JS_GLFW_SET_METHOD(extensionSupported);
	
	/* Joystick */
	JS_GLFW_SET_METHOD(joystickPresent);
	JS_GLFW_SET_METHOD(getJoystickAxes);
	JS_GLFW_SET_METHOD(getJoystickButtons);
	JS_GLFW_SET_METHOD(getJoystickName);
	
	/*************************************************************************
	* GLFW version
	*************************************************************************/
	
	JS_GLFW_CONSTANT(VERSION_MAJOR);
	JS_GLFW_CONSTANT(VERSION_MINOR);
	JS_GLFW_CONSTANT(VERSION_REVISION);
	
	/*************************************************************************
	* Input handling definitions
	*************************************************************************/
	
	/* Key and button state/action definitions */
	JS_GLFW_CONSTANT(RELEASE);
	JS_GLFW_CONSTANT(PRESS);
	JS_GLFW_CONSTANT(REPEAT);
	
	/* These key codes are inspired by the *USB HID Usage Tables v1.12* (p. 53-60),
	* but re-arranged to map to 7-bit ASCII for printable keys (function keys are
	* put in the 256+ range).
	*
	* The naming of the key codes follow these rules:
	*  - The US keyboard layout is used
	*  - Names of printable alpha-numeric characters are used (e.g. "A", "R",
	*    "3", etc.)
	*  - For non-alphanumeric characters, Unicode:ish names are used (e.g.
	*    "COMMA", "LEFT_SQUARE_BRACKET", etc.). Note that some names do not
	*    correspond to the Unicode standard (usually for brevity)
	*  - Keys that lack a clear US mapping are named "WORLD_x"
	*  - For non-printable keys, custom names are used (e.g. "F4",
	*    "BACKSPACE", etc.)
	*/
	
	/* The unknown key */
	JS_GLFW_CONSTANT(KEY_UNKNOWN);
	
	/* Printable keys */
	JS_GLFW_CONSTANT(KEY_SPACE);
	JS_GLFW_CONSTANT(KEY_APOSTROPHE);
	JS_GLFW_CONSTANT(KEY_COMMA);
	JS_GLFW_CONSTANT(KEY_MINUS);
	JS_GLFW_CONSTANT(KEY_PERIOD);
	JS_GLFW_CONSTANT(KEY_SLASH);
	JS_GLFW_CONSTANT(KEY_0);
	JS_GLFW_CONSTANT(KEY_1);
	JS_GLFW_CONSTANT(KEY_2);
	JS_GLFW_CONSTANT(KEY_3);
	JS_GLFW_CONSTANT(KEY_4);
	JS_GLFW_CONSTANT(KEY_5);
	JS_GLFW_CONSTANT(KEY_6);
	JS_GLFW_CONSTANT(KEY_7);
	JS_GLFW_CONSTANT(KEY_8);
	JS_GLFW_CONSTANT(KEY_9);
	JS_GLFW_CONSTANT(KEY_SEMICOLON);
	JS_GLFW_CONSTANT(KEY_EQUAL);
	JS_GLFW_CONSTANT(KEY_A);
	JS_GLFW_CONSTANT(KEY_B);
	JS_GLFW_CONSTANT(KEY_C);
	JS_GLFW_CONSTANT(KEY_D);
	JS_GLFW_CONSTANT(KEY_E);
	JS_GLFW_CONSTANT(KEY_F);
	JS_GLFW_CONSTANT(KEY_G);
	JS_GLFW_CONSTANT(KEY_H);
	JS_GLFW_CONSTANT(KEY_I);
	JS_GLFW_CONSTANT(KEY_J);
	JS_GLFW_CONSTANT(KEY_K);
	JS_GLFW_CONSTANT(KEY_L);
	JS_GLFW_CONSTANT(KEY_M);
	JS_GLFW_CONSTANT(KEY_N);
	JS_GLFW_CONSTANT(KEY_O);
	JS_GLFW_CONSTANT(KEY_P);
	JS_GLFW_CONSTANT(KEY_Q);
	JS_GLFW_CONSTANT(KEY_R);
	JS_GLFW_CONSTANT(KEY_S);
	JS_GLFW_CONSTANT(KEY_T);
	JS_GLFW_CONSTANT(KEY_U);
	JS_GLFW_CONSTANT(KEY_V);
	JS_GLFW_CONSTANT(KEY_W);
	JS_GLFW_CONSTANT(KEY_X);
	JS_GLFW_CONSTANT(KEY_Y);
	JS_GLFW_CONSTANT(KEY_Z);
	JS_GLFW_CONSTANT(KEY_LEFT_BRACKET);
	JS_GLFW_CONSTANT(KEY_BACKSLASH);
	JS_GLFW_CONSTANT(KEY_RIGHT_BRACKET);
	JS_GLFW_CONSTANT(KEY_GRAVE_ACCENT);
	JS_GLFW_CONSTANT(KEY_WORLD_1);
	JS_GLFW_CONSTANT(KEY_WORLD_2);
	
	/* Function keys */
	JS_GLFW_CONSTANT(KEY_ESCAPE);
	JS_GLFW_CONSTANT(KEY_ENTER);
	JS_GLFW_CONSTANT(KEY_TAB);
	JS_GLFW_CONSTANT(KEY_BACKSPACE);
	JS_GLFW_CONSTANT(KEY_INSERT);
	JS_GLFW_CONSTANT(KEY_DELETE);
	JS_GLFW_CONSTANT(KEY_RIGHT);
	JS_GLFW_CONSTANT(KEY_LEFT);
	JS_GLFW_CONSTANT(KEY_DOWN);
	JS_GLFW_CONSTANT(KEY_UP);
	JS_GLFW_CONSTANT(KEY_PAGE_UP);
	JS_GLFW_CONSTANT(KEY_PAGE_DOWN);
	JS_GLFW_CONSTANT(KEY_HOME);
	JS_GLFW_CONSTANT(KEY_END);
	JS_GLFW_CONSTANT(KEY_CAPS_LOCK);
	JS_GLFW_CONSTANT(KEY_SCROLL_LOCK);
	JS_GLFW_CONSTANT(KEY_NUM_LOCK);
	JS_GLFW_CONSTANT(KEY_PRINT_SCREEN);
	JS_GLFW_CONSTANT(KEY_PAUSE);
	JS_GLFW_CONSTANT(KEY_F1);
	JS_GLFW_CONSTANT(KEY_F2);
	JS_GLFW_CONSTANT(KEY_F3);
	JS_GLFW_CONSTANT(KEY_F4);
	JS_GLFW_CONSTANT(KEY_F5);
	JS_GLFW_CONSTANT(KEY_F6);
	JS_GLFW_CONSTANT(KEY_F7);
	JS_GLFW_CONSTANT(KEY_F8);
	JS_GLFW_CONSTANT(KEY_F9);
	JS_GLFW_CONSTANT(KEY_F10);
	JS_GLFW_CONSTANT(KEY_F11);
	JS_GLFW_CONSTANT(KEY_F12);
	JS_GLFW_CONSTANT(KEY_F13);
	JS_GLFW_CONSTANT(KEY_F14);
	JS_GLFW_CONSTANT(KEY_F15);
	JS_GLFW_CONSTANT(KEY_F16);
	JS_GLFW_CONSTANT(KEY_F17);
	JS_GLFW_CONSTANT(KEY_F18);
	JS_GLFW_CONSTANT(KEY_F19);
	JS_GLFW_CONSTANT(KEY_F20);
	JS_GLFW_CONSTANT(KEY_F21);
	JS_GLFW_CONSTANT(KEY_F22);
	JS_GLFW_CONSTANT(KEY_F23);
	JS_GLFW_CONSTANT(KEY_F24);
	JS_GLFW_CONSTANT(KEY_F25);
	JS_GLFW_CONSTANT(KEY_KP_0);
	JS_GLFW_CONSTANT(KEY_KP_1);
	JS_GLFW_CONSTANT(KEY_KP_2);
	JS_GLFW_CONSTANT(KEY_KP_3);
	JS_GLFW_CONSTANT(KEY_KP_4);
	JS_GLFW_CONSTANT(KEY_KP_5);
	JS_GLFW_CONSTANT(KEY_KP_6);
	JS_GLFW_CONSTANT(KEY_KP_7);
	JS_GLFW_CONSTANT(KEY_KP_8);
	JS_GLFW_CONSTANT(KEY_KP_9);
	JS_GLFW_CONSTANT(KEY_KP_DECIMAL);
	JS_GLFW_CONSTANT(KEY_KP_DIVIDE);
	JS_GLFW_CONSTANT(KEY_KP_MULTIPLY);
	JS_GLFW_CONSTANT(KEY_KP_SUBTRACT);
	JS_GLFW_CONSTANT(KEY_KP_ADD);
	JS_GLFW_CONSTANT(KEY_KP_ENTER);
	JS_GLFW_CONSTANT(KEY_KP_EQUAL);
	JS_GLFW_CONSTANT(KEY_LEFT_SHIFT);
	JS_GLFW_CONSTANT(KEY_LEFT_CONTROL);
	JS_GLFW_CONSTANT(KEY_LEFT_ALT);
	JS_GLFW_CONSTANT(KEY_LEFT_SUPER);
	JS_GLFW_CONSTANT(KEY_RIGHT_SHIFT);
	JS_GLFW_CONSTANT(KEY_RIGHT_CONTROL);
	JS_GLFW_CONSTANT(KEY_RIGHT_ALT);
	JS_GLFW_CONSTANT(KEY_RIGHT_SUPER);
	JS_GLFW_CONSTANT(KEY_MENU);
	JS_GLFW_CONSTANT(KEY_LAST);
	
	/*Modifier key flags*/
	
	/*If this bit is set one or more Shift keys were held down. */
	JS_GLFW_CONSTANT(MOD_SHIFT);
	/*If this bit is set one or more Control keys were held down. */
	JS_GLFW_CONSTANT(MOD_CONTROL);
	/*If this bit is set one or more Alt keys were held down. */
	JS_GLFW_CONSTANT(MOD_ALT);
	/*If this bit is set one or more Super keys were held down. */
	JS_GLFW_CONSTANT(MOD_SUPER);
	
	/*Mouse buttons*/
	JS_GLFW_CONSTANT(MOUSE_BUTTON_1);
	JS_GLFW_CONSTANT(MOUSE_BUTTON_2);
	JS_GLFW_CONSTANT(MOUSE_BUTTON_3);
	JS_GLFW_CONSTANT(MOUSE_BUTTON_4);
	JS_GLFW_CONSTANT(MOUSE_BUTTON_5);
	JS_GLFW_CONSTANT(MOUSE_BUTTON_6);
	JS_GLFW_CONSTANT(MOUSE_BUTTON_7);
	JS_GLFW_CONSTANT(MOUSE_BUTTON_8);
	JS_GLFW_CONSTANT(MOUSE_BUTTON_LAST);
	JS_GLFW_CONSTANT(MOUSE_BUTTON_LEFT);
	JS_GLFW_CONSTANT(MOUSE_BUTTON_RIGHT);
	JS_GLFW_CONSTANT(MOUSE_BUTTON_MIDDLE);
	
	/*Joysticks*/
	JS_GLFW_CONSTANT(JOYSTICK_1);
	JS_GLFW_CONSTANT(JOYSTICK_2);
	JS_GLFW_CONSTANT(JOYSTICK_3);
	JS_GLFW_CONSTANT(JOYSTICK_4);
	JS_GLFW_CONSTANT(JOYSTICK_5);
	JS_GLFW_CONSTANT(JOYSTICK_6);
	JS_GLFW_CONSTANT(JOYSTICK_7);
	JS_GLFW_CONSTANT(JOYSTICK_8);
	JS_GLFW_CONSTANT(JOYSTICK_9);
	JS_GLFW_CONSTANT(JOYSTICK_10);
	JS_GLFW_CONSTANT(JOYSTICK_11);
	JS_GLFW_CONSTANT(JOYSTICK_12);
	JS_GLFW_CONSTANT(JOYSTICK_13);
	JS_GLFW_CONSTANT(JOYSTICK_14);
	JS_GLFW_CONSTANT(JOYSTICK_15);
	JS_GLFW_CONSTANT(JOYSTICK_16);
	JS_GLFW_CONSTANT(JOYSTICK_LAST);
	
	/*errors Error codes*/
	
	/*GLFW has not been initialized.*/
	JS_GLFW_CONSTANT(NOT_INITIALIZED);
	/*No context is current for this thread.*/
	JS_GLFW_CONSTANT(NO_CURRENT_CONTEXT);
	/*One of the enum parameters for the function was given an invalid enum.*/
	JS_GLFW_CONSTANT(INVALID_ENUM);
	/*One of the parameters for the function was given an invalid value.*/
	JS_GLFW_CONSTANT(INVALID_VALUE);
	/*A memory allocation failed.*/
	JS_GLFW_CONSTANT(OUT_OF_MEMORY);
	/*GLFW could not find support for the requested client API on the system.*/
	JS_GLFW_CONSTANT(API_UNAVAILABLE);
	/*The requested client API version is not available.*/
	JS_GLFW_CONSTANT(VERSION_UNAVAILABLE);
	/*A platform-specific error occurred that does not match any of the more specific categories.*/
	JS_GLFW_CONSTANT(PLATFORM_ERROR);
	/*The clipboard did not contain data in the requested format.*/
	JS_GLFW_CONSTANT(FORMAT_UNAVAILABLE);
	
	JS_GLFW_CONSTANT(FOCUSED);
	JS_GLFW_CONSTANT(ICONIFIED);
	JS_GLFW_CONSTANT(AUTO_ICONIFY);
	JS_GLFW_CONSTANT(RESIZABLE);
	JS_GLFW_CONSTANT(VISIBLE);
	JS_GLFW_CONSTANT(DECORATED);
	
	JS_GLFW_CONSTANT(RED_BITS);
	JS_GLFW_CONSTANT(GREEN_BITS);
	JS_GLFW_CONSTANT(BLUE_BITS);
	JS_GLFW_CONSTANT(ALPHA_BITS);
	JS_GLFW_CONSTANT(DEPTH_BITS);
	JS_GLFW_CONSTANT(STENCIL_BITS);
	JS_GLFW_CONSTANT(ACCUM_RED_BITS);
	JS_GLFW_CONSTANT(ACCUM_GREEN_BITS);
	JS_GLFW_CONSTANT(ACCUM_BLUE_BITS);
	JS_GLFW_CONSTANT(ACCUM_ALPHA_BITS);
	JS_GLFW_CONSTANT(AUX_BUFFERS);
	JS_GLFW_CONSTANT(STEREO);
	JS_GLFW_CONSTANT(SAMPLES);
	JS_GLFW_CONSTANT(SRGB_CAPABLE);
	JS_GLFW_CONSTANT(REFRESH_RATE);
	JS_GLFW_CONSTANT(DOUBLEBUFFER);
	JS_GLFW_CONSTANT(TRUE);
	JS_GLFW_CONSTANT(FALSE);
	
	JS_GLFW_CONSTANT(CLIENT_API);
	JS_GLFW_CONSTANT(CONTEXT_VERSION_MAJOR);
	JS_GLFW_CONSTANT(CONTEXT_VERSION_MINOR);
	JS_GLFW_CONSTANT(CONTEXT_REVISION);
	JS_GLFW_CONSTANT(CONTEXT_ROBUSTNESS);
	JS_GLFW_CONSTANT(OPENGL_FORWARD_COMPAT);
	JS_GLFW_CONSTANT(OPENGL_DEBUG_CONTEXT);
	JS_GLFW_CONSTANT(OPENGL_PROFILE);
	
	JS_GLFW_CONSTANT(OPENGL_API);
	JS_GLFW_CONSTANT(OPENGL_ES_API);
	
	JS_GLFW_CONSTANT(NO_ROBUSTNESS);
	JS_GLFW_CONSTANT(NO_RESET_NOTIFICATION);
	JS_GLFW_CONSTANT(LOSE_CONTEXT_ON_RESET);
	
	JS_GLFW_CONSTANT(OPENGL_ANY_PROFILE);
	JS_GLFW_CONSTANT(OPENGL_CORE_PROFILE);
	JS_GLFW_CONSTANT(OPENGL_COMPAT_PROFILE);
	
	JS_GLFW_CONSTANT(CURSOR);
	JS_GLFW_CONSTANT(STICKY_KEYS);
	JS_GLFW_CONSTANT(STICKY_MOUSE_BUTTONS);
	
	JS_GLFW_CONSTANT(CURSOR_NORMAL);
	JS_GLFW_CONSTANT(CURSOR_HIDDEN);
	JS_GLFW_CONSTANT(CURSOR_DISABLED);
	
	JS_GLFW_CONSTANT(CONNECTED);
	JS_GLFW_CONSTANT(DISCONNECTED);
	
	// test scene
	JS_GLFW_SET_METHOD(testScene);
	JS_GLFW_SET_METHOD(testJoystick);
	
	return exports;
	
}


NODE_API_MODULE(glfw, initModule)
