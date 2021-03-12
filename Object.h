#pragma once

class Object abstract
 {
 private:
	 bool Live = true;
 public:
	 Object() {}
	 ~Object() {}
	 
 public:
	 virtual void Update() PURE;
	 virtual void Render() PURE;
	 virtual void Collion(Object * obj) PURE;
	 void DieObj() { Live = false; }
	 bool ObjectLive() { return Live; }
};

