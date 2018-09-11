     
       ____                
      / __ \               
     | |  | |___ _   _ ___ 
     | |  | / __| | | / __|
     | |__| \__ \ |_| \__ \
      \___\_\___/\__, |___/
                  __/ |    
                 |___/     


# Library Interface

## Constructor Arguments
	- System Type: String (current options: Hamiltonian)
	- Generator: Array or list of arrays
	- Simulation Parameters: Json/Dictionary-Like

## Public Methods
	- get_state()
		Params: None
		Returns: 
		- Array, the current wavefunction of the system
	- get_history()
		Params: None
		Returns:
		- Array, the entire history of the system's measurements
	- measure(povm_id)
		Params:
		- povm_id is an int identifying which POVM element to use in measurement
		Returns:
		- Int, the result of the measurement
		Measures the system once and returns the result
	- run_continuous()
		Params: None
		Returns: None
		Starts running the simulation continuously at the system clock-speed
	- run_one_step()
		Params: None
		Returns: None
		Runs the simulation for one evolution step
	- set_initial_state(state)
		Params:
		- state is an array which defines the initial wavefunction
		Returns: None
		Sets the initial state of the system to be simulated
	- setup(overrides)
		Params:
		- overrides is a json/dict containing any defaults that should be overridden
		Returns:
		- reference to the system
		Sets up the simulation environment (POVMs, propogators, etc.)
	- stop()
		Params: None
		Returns: None
		Stops the simulation
	- restart()
		Params: None
		Returns: None
		Restarts the simulation from the beginning

### Notes on Public Methods

	- get_history() will require that every measurement is stored internally with the measurement result, the input, and the time of measurement
	- get_state() will be called every clock cycle in order to update the UI
