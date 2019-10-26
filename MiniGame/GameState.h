#pragma once

class GameState
{
public: 
	virtual bool Init () = 0;
	virtual bool Update () = 0;
	virtual bool Destroy () = 0;
};

template <class T>
GameState* CreateClass ()
{
	return new T ();
}