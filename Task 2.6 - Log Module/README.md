# Create Modules with private internal state and public functions
# Task:
Create a log module that allows to register messages and errors. The module must contain a internal toggle to activate / disable the log.

# Requirements:
* ## log.h: 
    * Must contain Include Guards
    * void Log_msg(const char *mensagem);
    * void Log_erro(const char *erro);
    * void Log_ativar(int estado); // 1 = on, 0 = off

* ## log.c:
    * Implement the functions declared in log.c
    * Internal static variable: static int on = 1; // inicialy active

* ## main.c:
    * Test the 3 functions