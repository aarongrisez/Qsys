     
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
	- get_pitches()
		Params: None
		Returns:
		- Array, list of all pitches used in this simulation

		Example:
		A Qsys instantiated to simulate 5 pitches (C, D, E, F, G) would return

			['C', 'D', 'E', 'F', 'G']

	- get_state()
		Params: None
		Returns: 
		- Array, the current wavefunction of the system

		Example:

			[0.57735+0j, 0-0.57735j, 0+0j, 0.57735+0j, 0+0j]

	- get_history()
		Params: None
		Returns:
		- Array, the entire history of the system's measurements
		
		Each time step is stored as: [MeasurementBoolean, MeasurementSetting (that is, user input), MeasurementResult]

		Example:
		A system that has run for 3 time steps with a measurement of the F pitch during the third step and sounded a C would return

			[[False, None, None], [False, None, None], [True, F, C]]

	- measure(povm_id)
		Params:
		- povm_id is an int identifying which POVM to use in measurement
		Returns:
		- String, the result of the measurement
		Triggers the process for measurement, measures the system once and returns the result

		Example: system that yields a measurement result of E would return

			'E' 

	- run_continuous()
		Params: None
		Returns: None
		Starts running the simulation continuously at the system clock-speed
		Spawns background process where every time step, run_one_step() is called
		Includes a listener: if no user input, evolves the state
				     if user input, initiates measurement

	- run_one_step()
		Params: None
		Returns: None
		Runs the simulation for one evolution step

	- set_initial_state(state) ***I think we can make this private***
		Params:
		- state is an array which defines the initial wavefunction
		Returns: None
		Sets the initial state of the system to be simulated

	- setup(parameters, overrides)
		Params:
		- params is a json/dict containing POVMs, initial state, and Hamiltonian
		- overrides is a json/dict containing any defaults that should be overridden (like simulation time step)
		Returns:
		- reference to the system
		Sets up the simulation environment

		Parameters Example:

			***POVMs might be missing a bracket or two, it should be a list which contains 2 sublists, each which contain 2 matrices. The two matrices in each sublist should sum to the identity matrix***

		{
			'POVMs': [[[[.3, 0], [[.7, 0]    [[[1, 0], [[0, 0],
				    [0, .7]]  [0, .3]]],   [0, 0]], [0, 1]]]],
			'Initial state': [0.707+0j, 0-0.707j],
			'Hamiltonian': [[cos(t), sin(t)],
					[sin(t), -cos(t)]]
		}

	- stop()
		Params: None
		Returns: None
		Stops the simulation, halts the process spawned in run_continuous()

	- restart()
		Params: None
		Returns: None
		Restarts the simulation from the beginning
		Deletes all current history, halts the current run_continuous() process, and restarts the process using the original initial conditions

### Notes on Public Methods

	- get_history() will require that every measurement is stored internally with the measurement result, the input, and the time of measurement
	- get_state() will be called every clock cycle in order to update the UI
