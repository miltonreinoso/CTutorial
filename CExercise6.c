/*Se debe implementar una máquina de estados sencilla. Dados los siguientes estímulos:
enum Stimulus
{
	TurnOn,
	TurnOff,
	SpeedUp,
	SpeedDown
};

y los siguientes estados:
enum State
{
	Off,
	Stopped,
	Walking,
	Running,
	Error
};

Implementado la siguiente Lógica:

Estado inicial: Off

Off ­­ TurnOn ­­>Stopped ­­ SpeedUp ­­> Walking ­­ SpeedUp ­­> Running ­­ SpeedUp ­­>Error

   						<­­ SpeedDown ­­        <­­SpeedDown ­­

De cualquier se pasa a Off con TurnOff
SpeedUp en Running lleva a Error
SpeedDown en Stopped también lleva a Error.
De Error sólo se sale con TurnOff. Cualquier otro estado lo conserva en Error
se debe implementar la función

void stimulate(struct FSM* fsm, enum Stimulus stimulus);

Que estimulará la máquina fsm con el estímulo stimulus avanzando al siguiente estado. Por cada
transición la máquina fsm debe imprimir por salida estándar:

[Estado anterior] ­­­­ <estímulo> ­­­­­> [Estado nuevo]

Se debe implementar también un main que estimule la máquina. Junto a la implementación de
este ejercicio se pedirá un diagrama de estados con las transiciones de la máquina de estados.*/

#include <stdio.h>

enum Stimulus
{
	TurnOn,
	TurnOff,
	SpeedUp,
	SpeedDown
};

enum State
{
	Off,
	Stopped,
	Walking,
	Running,
	Error
};

char * STATE_STRINGS [5]= {"Off", "Stopped", "Walking","Running","Error"} ;
char * STIMULUS_STRINGS [4]= {"TurnOn", "TurnOff", "SpeedUp","SpeedDown"} ;

struct FSM
{
	enum State currentState;
	enum State oldState;
};

void stimulate(struct FSM*, enum Stimulus);

int main ()
{
	struct FSM fsm;
	fsm.currentState = Off;
	fsm.oldState = Off;


	// Correct processig of the FSM
	printf("------------- Correct processig -------------\n");
	stimulate(&fsm, TurnOn);
	stimulate(&fsm, SpeedUp);
	stimulate(&fsm, SpeedUp);
	stimulate(&fsm, SpeedDown);
	stimulate(&fsm, SpeedDown);
	stimulate(&fsm, TurnOff);

	printf("----------------- Bad processig ----------------\n");
	// Bad processig of the FSM
	stimulate(&fsm, TurnOn);
	stimulate(&fsm, SpeedDown);
	stimulate(&fsm, TurnOn);
	stimulate(&fsm, TurnOff);
}

void stimulate(struct FSM* fsm, enum Stimulus stimulus)
{
	if (fsm->currentState == Off && stimulus == TurnOn)
	{ 	
		fsm->oldState = fsm->currentState;
		fsm->currentState = Stopped;
		printf("[%s] ­­­­ <%s> ­­­­­> [%s]\n",STATE_STRINGS[fsm->oldState], STIMULUS_STRINGS[stimulus] ,STATE_STRINGS[fsm->currentState]);
	}
	else if (fsm->currentState == Stopped && stimulus == SpeedUp)
	{ 	
		fsm->oldState = fsm->currentState;
		fsm->currentState = Walking;
		printf("[%s] ­­­­ <%s> ­­­­­> [%s]\n",STATE_STRINGS[fsm->oldState], STIMULUS_STRINGS[stimulus] ,STATE_STRINGS[fsm->currentState]);
	}
	else if (fsm->currentState == Walking)
	{ 	
		if(stimulus == SpeedUp)
		{
			fsm->oldState = fsm->currentState;
			fsm->currentState = Running;
			printf("[%s] ­­­­ <%s> ­­­­­> [%s]\n",STATE_STRINGS[fsm->oldState], STIMULUS_STRINGS[stimulus] ,STATE_STRINGS[fsm->currentState]);	
		}
		if (stimulus == SpeedDown)
		{
			fsm->oldState = fsm->currentState;
			fsm->currentState = Stopped;
			printf("[%s] ­­­­ <%s> ­­­­­> [%s]\n",STATE_STRINGS[fsm->oldState], STIMULUS_STRINGS[stimulus] ,STATE_STRINGS[fsm->currentState]);
		}
	}
	else if (fsm->currentState == Running && stimulus == SpeedDown)
	{ 	
		fsm->oldState = fsm->currentState;
		fsm->currentState = Walking;
		printf("[%s] ­­­­ <%s> ­­­­­> [%s]\n",STATE_STRINGS[fsm->oldState], STIMULUS_STRINGS[stimulus] ,STATE_STRINGS[fsm->currentState]);
	}
	else if (stimulus == TurnOff)
	{ 	
		fsm->oldState = fsm->currentState;
		fsm->currentState = Off;
		printf("[%s] ­­­­ <%s> ­­­­­> [%s]\n",STATE_STRINGS[fsm->oldState], STIMULUS_STRINGS[stimulus] ,STATE_STRINGS[fsm->currentState]);
	}
	else
	{
		fsm->oldState = fsm->currentState;
		fsm->currentState = Error;
		printf("[%s] ­­­­ <%s> ­­­­­> [%s]\n",STATE_STRINGS[fsm->oldState], STIMULUS_STRINGS[stimulus] ,STATE_STRINGS[fsm->currentState]);
	} 	
}