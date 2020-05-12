#pragma once
#include <iostream>;
#include <vector>;
#include <string>;


using namespace std;

class Vector3;

vector<Vector3> Players;

vector<Vector3> merge(vector<Vector3>players, int l, int m, int r)
{
	int ii, j, k;
	int n1 = m - l + 1;
	int n2 = r - m;

	vector<Vector3> left, right;
	for (int ii = 0; ii < n1; ii++)
	{
		left.push_back(players.at(l + ii));
	}
	for (int j = 0; j < n2; j++)
	{
		right.push_back(players.at(m + 1 + j));
	}

	ii = 0; 
	j = 0; 
	k = l;

	while (ii < n1 && j < n2)
	{
		if (left.at(ii).x <= right.at(j).x)
		{
			players.at(k) = left.at(ii);
			ii++;
		}
		else
		{
			players.at(k) = right.at(j);
			j++;
		}
		k++;
	}

	while (ii < n1)
	{
		players.at(k) = left.at(ii);
		ii++;
		k++;
	}

	while (j < n2)
	{
		players.at(k) = right.at(j);
		j++;
		k++;
	}
}

void mergeSort(vector<Vector3> players, int l, int r)
{
	if (l < r)
	{
		int m = l + (r - 1) / 2;

		mergeSort(players, l, m);
		mergeSort(players, m + 1, r);

		merge(players, l, m, r);
	}
}

class Vector3
{
public:
	double x;
	double y;
	double z;

	Vector3()
	{
		x = y = z = 0;
	}

	double getX() { return x; }

	double getY() { return y; }

	Vector3(double Mx,double My,double Mz)
	{
		x = Mx;
		y = My;
		z = Mz;
	}

	Vector3(double Mx, double My)
	{
		Vector3(Mx, My, 0);
	}
	
	Vector3 operator+ (Vector3 a)
	{
		return Vector3(x + a.x, y + a.y, z + a.z);

	}

	Vector3 operator- (Vector3 a)
	{
		return Vector3(x - a.x, y - a.y, z - a.z);
	}

	double Magnitude()
	{
		return (double) (sqrt((float)(x * x + y * y + z * z)));
	}

	bool Equals(Vector3 vec)
	{
		if (vec.x == x && vec.y == y && vec.z == z)
		{
			return true;
		}
		return false;
	}

	double  Distance(Vector3 vec1, Vector3 vec2)
	{
		return (vec1 - vec2).Magnitude();
	}

	string toString()
	{
		return to_string(x) + "; " + to_string(y) + "; " + to_string(z);
	}

};



class GameController
{
public:

	void addPlayers(double lon, double lat)
	{
		Players.push_back(Vector3(lon, lat));
	}

	void addPlayers( double lon, double lat, double alt)
	{
		Players.push_back(Vector3(lon, lat, alt));
	}

	void clearAllPlayers()
	{
		Players.clear();
	}

	string findMidpoint()
	{
		sortPlayers(Players);
		return isConvex(Players).toString();
	}


private:

	Vector3 findOrigin(vector<Vector3> players)
	{
		float tmpx = 0.0f;
		float tmpy = 0.0f;
		float tmpz = 0.0f;
		for each (Vector3 player in players)
		{
			tmpx += player.x;
			tmpy += player.y;
			tmpz += player.z;
		}

		return Vector3((double)tmpx / players.size(), (double)tmpy / players.size(), (double)tmpz / players.size());
	}

	void sortPlayers(vector<Vector3> players)
	{
		//NOTE: Deleted sorting and need to recreate system for Closest Pair of Points O(nlogn)
		 mergeSort(players,0, players.size);
	}

	Vector3 findOrigin(Vector3 vec1, Vector3 vec2, Vector3 vec3)
	{
		return Vector3((vec1.x + vec2.x + vec3.x) / 3, (vec1.y + vec2.y + vec3.y) / 3, (vec1.z + vec2.z + vec3.z) / 3);
	}


	Vector3 Triangulate(vector<Vector3> players)
	{
		vector<Vector3> triangle;
		for (int ii = 0; ii < players.size(); ii++)
		{
			int xx = (ii + 1) % players.size();
			int yy = (ii + 1) % players.size();

			triangle.push_back(findOrigin(players.at(ii), players.at(xx), players.at(yy)));
		}

		return findOrigin(triangle);
	}

	float CrossProductLength(float Ax, float Ay, float Bx, float By, float Cx, float Cy)
	{
		float BAx = Ax - Bx;
		float BAy = Ay - By;
		float BCx = Cx - Bx;
		float BCy = Cy - By;

		return (BAx * BCy - BAy * BCx);
	}

	Vector3 isConvex(vector<Vector3> players)
	{
		for (int pointA = 0; pointA < players.size(); pointA++)
		{
			bool neg_flag = false;
			bool pos_flag = false;
			int pointB = (pointA + 1) % players.size();
			int pointC = (pointB + 1) % players.size();

			float cross_product = CrossProductLength(
				players.at(pointA).x,
				players.at(pointA).y,
				players.at(pointB).x,
				players.at(pointB).y,
				players.at(pointC).x,
				players.at(pointC).y);

			if (cross_product < 0)
			{
				neg_flag = true;
			}
			if (cross_product > 0)
			{
				pos_flag = true;
			}
			if (neg_flag && pos_flag)
			{
				return Triangulate(players);
			}
		}

		return findOrigin(players);
	}
};
