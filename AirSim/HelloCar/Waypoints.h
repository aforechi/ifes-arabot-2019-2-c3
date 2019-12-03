#pragma once
#include <iostream>
#include <vector>
#include <fstream>

class Waypoints
{
private:
	std::vector<double>x;
	std::vector<double>y;
	std::vector<double>v;
public:
	Waypoints() {
		
	}
	
	void AddWaypoints(double xx, double yy, double vv){
		this->x.push_back(xx);
		this->y.push_back(yy);
		this->v.push_back(vv);
	}

	void SaveWaypoints(std::string filename){
		std::ofstream Valores(filename);
		for(int i=0;i<x.size();i++)
			Valores << x[i] << ";" << y[i] << ";" << v[i] << std::endl;
		Valores.close();

	}
	void LoadWaypoints(std::string filename) {
		std::ifstream Valores(filename);
		std::string linha, coluna;
		while (!Valores.eof()) {
			std::getline(Valores, linha);
			std::istringstream Colunas(linha);
			while (!Colunas.eof()) {
				std::getline(Colunas, coluna, ';');
				if(coluna!="")
					x.push_back(atof(coluna.c_str()));
				std::getline(Colunas, coluna, ';');
				if (coluna != "")
					y.push_back(atof(coluna.c_str()));
				std::getline(Colunas, coluna, ';');
				if (coluna != "")
					v.push_back(atof(coluna.c_str()));
			}
		}
		Valores.close();
	}
};

