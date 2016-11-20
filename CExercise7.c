/*Implementar un sistema multi­idiomas de mensajes. Se requiere que dados dos enumerados que

representen idioma y mensajes se devuelva un const char* con el texto correspondiente.

enum Languages

{

Spanish,

English

};

enum Messages

{

HelloWorld,

OutOfMemory,

FileNotFound

};

const char* getMessage(enum Languages language, enum Messages message);

Asumiendo que el valor del enumerado es consecutivo, empezando en cero: ¿Se le ocurre alguna

manera de saber cuantos mensajes y lenguajes hay en el enumerado?*/

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

struct FSM
{
	State OldState,
	State CurrentState
};

void stimulate(struct FSM*, enum Stimulus);

int main ()
{
	struct FSM fsm;

	// Correct processig of the FSM
	stimulate(fsm, Stimulus.TurnOn);
	stimulate(fsm, Stimulus.SpeedUp);
	stimulate(fsm, Stimulus.SpeedUp);
	stimulate(fsm, Stimulus.SpeedDown);
	stimulate(fsm, Stimulus.SpeedDown);
	stimulate(fsm, Stimulus.TurnOff);

	// Bad processig of the FSM
	stimulate(fsm, Stimulus.TurnOn);
	stimulate(fsm, Stimulus.SpeedDown);
	stimulate(fsm, Stimulus.TurnOn);
	stimulate(fsm, Stimulus.TurnOff);
}

void stimulate(struct FSM* fsm, enum Stimulus stimulus)
{
	printf("The machine has been stimulated%s\n", stimulus);
}
