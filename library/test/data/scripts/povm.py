"""
povm.py
Class for the POVM object

Basic Principles:
-----------------
    1. Indexing is by input state
    2. Mean of the generating distribution is the "central state"
    3. 
"""

import numpy as np
from scipy.stats import binom

NUM_DIMS = 5        # Number of dimensions
class POVM(object):

    def __init__(dims):
        self.dimension = dims

    def generate_binomial_dist(std_divs):
        pass

    def generate_random_dist():
        pass


