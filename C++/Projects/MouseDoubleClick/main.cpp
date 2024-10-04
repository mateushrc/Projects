#include <windows.h>
#include <iostream>

int main() {
    bool isClicked = false;  // Flag para verificar se o clique já foi processado

    // Loop infinito para capturar eventos de mouse
    while (true) {
        // Verificando se o botão esquerdo está pressionado
        if (GetAsyncKeyState(VK_LBUTTON) & 0x8000) {
            // Se o clique ainda não foi processado
            if (!isClicked) {
                // Simular um double click
                POINT cursorPos;
                GetCursorPos(&cursorPos);  // Obtém a posição atual do cursor

                mouse_event(MOUSEEVENTF_LEFTDOWN, cursorPos.x, cursorPos.y, 0, 0);
                mouse_event(MOUSEEVENTF_LEFTUP, cursorPos.x, cursorPos.y, 0, 0);
                mouse_event(MOUSEEVENTF_LEFTDOWN, cursorPos.x, cursorPos.y, 0, 0);
                mouse_event(MOUSEEVENTF_LEFTUP, cursorPos.x, cursorPos.y, 0, 0);

                std::cout << "Double click simulado" << std::endl;

                // Marcar que o clique foi processado
                isClicked = true;
            }
        }
        // Verifica se o botão foi solto para redefinir a flag
        else {
            isClicked = false;  // Redefinir a flag para o próximo clique
        }

        Sleep(100);  // Pequeno atraso para evitar uso excessivo de CPU
    }

    return 0;
}
