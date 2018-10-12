"""
Simulation Data Generator
"""
import numpy as np
import scipy
import json
import matplotlib.pyplot as plt
from scipy.integrate import ode

class System(object):

    def __init__(self, initial_state, hamiltonian, t_final=50, dt=.01):
        self.initialState = initial_state       #Initial condition for solution
        self.currentState = initial_state
        self.hamiltonian = hamiltonian          #Hamiltonian for the system
        self.t = 0                              #Current time for the system
        self.renormalizations = 0               #Keep track of renormalizations
                                                #If this number grows
                                                #significantly, we have a
                                                #problem with our implementation

        self.tFinal = t_final                   #Stop time for the simulation
        self.dt = dt                            #Differential time step for the
                                                #simulation

        self.history = [self.initialState]      #A record of the currentState
                                                #attribute through the entire
                                                #simulation

    def schrodinger(self):
        """
        Returns:
        --------
            vector
                differential time step for wavefunction evolution
        """
        return 1 / (1j) * np.dot(self.hamiltonian(self.solver.t), self.currentState)

    def propogator(self, t):
        """
        This method should only ever be called during pre-processing (unless we
        have implemented adaptive processing--talk to Aaron or Sam about this,
        assume adaptive processing is not implemented); it generates a single
        propogator and should be called many times to generate the entire list
        of propogators

        Returns:
            matrix (complex float entries)
                This method returns the propogator for a particular time step.
                Note: this implementation is slightly different from that in
                math.pdf. I will update that document with this implementation
                as a possible alternative
        """
        return scipy.linalg.expm(1j * self.hamiltonian(t) * t)

    def norm(self):
        """
        If ever this method returns a value that is not sufficiently close to
        1.0 (say, off by .0001), the renormalization method should be called

        Returns:
        --------
            scalar (float, real)
                the norm of the current state vector 
        """
        return np.linalg.norm(self.currentState)

    def renormalize(self):
        """
        This method shouldn't be called very often, if at all. The propogator
        has the property of unitarity; that is, it should preserve the norm of
        the state vector it acts on
        """
        print('renormalizing')
        self.renormalizations += 1
        self.currentState = self.currentState / self.norm()

    def run(self):
        """
        Returns:
        --------
            None
        """
        while self.t < self.tFinal:
            self.t += self.dt
            u = self.propogator(self.t)
            self.currentState = np.dot(u, self.initialState)
            self.history.append(self.currentState)
            if abs(self.norm() - 1) >= .5:
                self.renormalize()

