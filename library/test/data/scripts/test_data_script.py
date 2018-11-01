import system

#INITIAL STATES
###############
x0 = np.array([0,1])
#x0 = np.array([0,0,1])

#HAMILTONIANS
###############

#2D_TimeDependent
def h(t):
    return np.matrix([[np.cos(t), 3 + 1j * np.sin(t)], [3 - 1j * np.sin(t), np.cos(t)]])
#as string
hamiltonian = '[[cos(t),3+i(sin(t))],[3-i(sin(t)),cos(t)]]'

#ND_TimeIndependent
n = 3
vecs = [np.random.rand(n) for i in range(4)]
real = np.matrix(np.outer(vecs[0], vecs[1]))
imag = np.matrix(np.outer(vecs[2], vecs[3]))
temp = real + 1j * imag
herm = 1/2 * (temp + temp.getH())
#def h(t):
#    return herm

#3D_TimeDependent
#def h(t):
#    return np.matrix([[np.cos(t), 3 + 1j * np.sin(t)], [3 - 1j * np.sin(t), np.cos(t)]])

#STRING PARSIN
b = str(herm.tolist()).replace('\n ', ',')
c = b.replace('<ufunc','').replace('>','')
d = c.replace('(', '').replace(')', '')
e = d.replace(' ', '').replace('j', 'i')
print(e)

s = System(x0, h)
s.run()
x = [str(i.tolist()) for i in s.history]
dataDict = {
    'testName': '2D_Hamiltonian_TimeDependent',
    'testType': 'HamiltonianSimulation',
    'hamiltonian': hamiltonian,
    'initialState': '[0,1]',
    'simulationData': x,
    'timeStep': s.dt,
    'finalTime': s.tFinal
}
with open(dataDict['testName'] + '.json', 'w') as o:
    json.dump(dataDict, o)
with open(dataDict['testName'] + '.json', 'r') as i:
    data = i.read().replace('(','').replace(')','')
    data = data.replace(' ','').replace('j','i')
with open(dataDict['testName'] + '.json', 'w') as o:
    o.write(data)
