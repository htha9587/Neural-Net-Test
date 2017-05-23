//============================================================================
// Name        : Neural Net Test.cpp
// Author      : htha9587
// Version     : 0.1.
// Copyright   : Your copyright notice.
// Description : Neural Net C++ Practice.
//============================================================================

#include <iostream>
#include <vector>
using namespace std;

class Neuron {};

typedef vector<Neuron> Layer;

class Net
{
public:
	Net(const vector<unsigned> &topology);
	void feedForward(const vector<double> &inputVals) {};
	void backProp(const vector<double> &targetVals) {};
	void getResults(vector<double> &resultVals) const {};

private:
	vector<Layer> m_layers;
};

Net::Net(const vector<unsigned> &topology)
{
	unsigned numLayers = topology.size();
	for(unsigned layerNum = 0; layerNum < numLayers; ++layerNum)
	{
		m_layers.push_back(Layer());

		//The next layer of neurons is made, it will be filled by neurons and a bias neuron.
		for(unsigned neuronNum= 0; neuronNum <= topology[layerNum]; ++ neuronNum)
		{
			m_layers.back().push_back(Neuron());
			cout << "Created a neuron!" << endl;
		}
	}
}

int main()
{
	vector<unsigned> topology;
	topology.push_back(3);
	topology.push_back(2);
	topology.push_back(1);
	Net myNet(topology);

	vector<double> inputVals;
	myNet.feedForward(inputVals);

	vector<double> targetVals;
	myNet.backProp(targetVals);

	vector<double> resultVals;
	myNet.getResults(resultVals);

}
