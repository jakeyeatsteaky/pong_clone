#include <Windows.h>

int WIDTH = 1920;
int HEIGHT = 1080;
bool destroy = false;


LRESULT window_callback(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam) {
	LRESULT result = 0;
	switch (uMsg) {
	case WM_CLOSE:
		destroy = DestroyWindow(hwnd);
		break;
	case WM_DESTROY:
		PostQuitMessage(0);
		break;
	default:
		result = DefWindowProcW(hwnd, uMsg, wParam, lParam);
	}
	return result;
}


int WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nShowCmd) {
	// Create a window
	WNDCLASS window = {};
	window.style = CS_HREDRAW | CS_VREDRAW;
	window.lpszClassName = L"Jake's First Game";
	window.lpfnWndProc = window_callback;

	RegisterClass(&window);

	HWND gameWindow = CreateWindow(window.lpszClassName, L"Game Window", WS_OVERLAPPEDWINDOW | WS_VISIBLE, CW_USEDEFAULT, CW_USEDEFAULT, WIDTH, HEIGHT, 0, 0, hInstance, 0);

	while (!destroy) {
		// Input
		MSG message;
		while (PeekMessage(&message, gameWindow, 0, 0, PM_REMOVE)) {
			//Dispatch message to the callback
			TranslateMessage(&message);
			DispatchMessage(&message);
		}
		// Simulate
		// Render
	}
}