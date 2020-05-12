

#include "Ray.hpp"


#include <iostream>//;
#include <vector>//;
#include <math.h>

using namespace std;

extern "C" 


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

    Vector3(double Mx, double My, double Mz)
    {
        x = Mx;
        y = My;
        z = Mz;
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
        return (double)(sqrt((float)(x * x + y * y + z * z)));
    }

    bool Equals(Vector3 vec)
    {
        if (vec.x == x && vec.y == y && vec.z == z)
        {
            return true;
        }
        return false;
    }

    double  Distance(Vector3 vec1)
    {
        Vector3 temp = Vector3(x,y,z);
        return (temp - vec1).Magnitude();
    }

};


class Player_track
{
public:
    Player_track(string n, Vector3 pos)
    {
        playerpos = pos;
        name = n;
    }
    
    void setFwd(Vector3 fwd) { playerfwd = fwd; }

    Vector3 getPos() { return playerpos; }
    Vector3 getFwd() { return playerfwd; }
    string getName() { return name; }


private:
    Vector3 playerpos;
    Vector3 playerfwd;
    string name;
};

vector<Player_track> Players;

class Raytrace
{
public:

    void addPlayers(string name, int lon, int lat, int alt)
    {
        Players.push_back(Player_track(name, Vector3(lon, lat, alt)));
    }

    void clearPlayers()
    {
        Players.clear();
    }

    bool checkPlayers(string name, int lon, int lat)
    {
        Player_track P1 = Player_track(name, Vector3(lon, lat, 0));
        for (int ii = 0; ii < Players.size(); ii++)
        {
            Player_track P2 = Players.at(ii % Players.size());
            if (checkTag(P1, P2) == true)
            {
                return true;
            }
        }
        
        return false;
    }

    bool checkPlayers(string name, int lon, int lat,int alt)
    {
        Player_track P1 = Player_track(name, Vector3(lon, lat, alt));
        for (int ii = 0; ii < Players.size(); ii++)
        {
            Player_track P2 = Players.at(ii % Players.size());
            if (checkTag(P1,P2) == true)
            {
                return true;
            }
        }
         return false;
    }

    vector<Player_track> getPlayers() { return allPlayers; }

private:

    Raytrace()
    {
        maxdist = 100;
        maxAngle = 135;
    }

    vector<Player_track> allPlayers;
    double maxdist;
    double maxAngle;
    
    bool checkTag(Player_track a, Player_track b)
    {
        Vector3 tempa = a.getPos();
        Vector3 fwd = a.getPos() + Vector3(0,1,0);
        Vector3 tempb = b.getPos();
        if (tempa.Distance(tempb) < maxdist) { return getAngle(tempa, fwd, tempb); }
        return false;
    }

    bool getAngle(Vector3 a,Vector3 fwd, Vector3 b)
    {
        Vector3 V1 = Vector3(fwd.x - a.x, fwd.y - a.y, fwd.z - a.z);
        Vector3 V2 = Vector3(b.x - a.x, b.y - a.y, b.z - a.z);
        
        double V1mag = V1.Magnitude();
        double V2mag = V2.Magnitude();

        Vector3 V1norm = Vector3(V1.x / V1mag, V1.y / V1mag, V1.z / V1mag);
        Vector3 V2norm = Vector3(V2.x / V2mag, V2.y / V2mag, V2.z / V2mag);

        double res = V1norm.x * V2norm.x + V1norm.y * V2norm.y + V1norm.z * V2norm.z;

        double angle = acos(res) * 180.0 / 3.141592653589793;

        if (angle > maxAngle) { return true; }
        return false;
    }
};
