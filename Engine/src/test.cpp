#include <iostream>
#include "test.hpp"

#include <glad/glad.h>
#include <GLFW/glfw3.h>

namespace Engine
{
    int sey_hello()
    {
        // glfw: инициализация и конфигурирование
        glfwInit();
        glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
        glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
        glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    
    // Раскомментируйте данную часть кода, если используете macOS
    
        #ifdef __APPLE__
            glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
        #endif
    
    
        // glfw: создание окна
        GLFWwindow* window = glfwCreateWindow(1024, 720, "OpenGL for Ravesli.com", NULL, NULL);
        if (window == NULL)
        {
            std::cout << "Failed to create GLFW window" << std::endl;
            glfwTerminate();
            return -1;
        }
        glfwMakeContextCurrent(window);
        
        // glad: загрузка всех указателей на OpenGL-функции
        if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
        {
            std::cout << "Failed to initialize GLAD" << std::endl;
            return -1;
        }    
    
        // Цикл рендеринга
        while (!glfwWindowShouldClose(window))
        {
           
            
            
            // Выполнение рендеринга
            glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
            glClear(GL_COLOR_BUFFER_BIT);
    
            // glfw: обмен содержимым front- и back-буферов. Отслеживание событий ввода/вывода (была ли нажата/отпущена кнопка, перемещен курсор мыши и т.п.)
            glfwSwapBuffers(window);
            glfwPollEvents();
        }
    
        // glfw: завершение, освобождение всех ранее задействованных GLFW-ресурсов
        glfwTerminate();
    }
}
