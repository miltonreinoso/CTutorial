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
