#pragma once
#include "RenderEngine.h"
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <glm/gtx/vector_angle.hpp>
#include <SOIL/SOIL.h>
#include "Shader.h"
#include "Object3D.h"
#include "Light.h"
#include "Camera.h"

class Demo :
	public RenderEngine
{
public:
	Demo();
	~Demo();

	Object3D cube;
	Object3D cubesides;
	Object3D cube2;
	Object3D cube2sides;
	Object3D cubeup;
	Object3D cube2up;
	Object3D cube3;
	Object3D cube4;
	Object3D cube4up;
	Object3D cube5;
	Object3D cube6d;
	Object3D cube6b;
	Object3D cube6bout;
	Object3D cube6kr;
	Object3D cube6kn;
	Object3D cube6a;
	Object3D cube7;
	Object3D cube7d;
	Object3D cube3up;
	Object3D cube8;
	Object3D cube8side;
	Object3D cube8up;
	Object3D cube9;
	Object3D cube9side;
	Object3D plane;
private:
	GLuint depthmapShader, shadowmapShader, texture_id, plane_texture, stexture, stexture2, depthMapFBO, depthMap;
	GLuint VAO, VBO, EBO, planeVBO, planeVAO, planeEBO;
	Shader shader;
	Light light;
	Camera camera;
	const unsigned int SHADOW_WIDTH = 1024, SHADOW_HEIGHT = 1024;
	virtual void Init();
	virtual void DeInit();
	virtual void Update(double deltaTime);
	virtual void Render();
	virtual void ProcessInput(GLFWwindow* window);
	void BuildTexturedPlane();
	void BuildDepthMap();
	void BuildShaders();
	void BuildObject();
	void CursorMovement();
	//Build Camera
	void BuildCamera();
	// Build Plane
	void BuildPlane();
	//Build Cube
	void BuildCube();
	void BuildCubesides();
	void BuildCubeup();
	void BuildCube2();
	void BuildCube2sides();
	void BuildCube2up();
	void BuildCube3();
	void BuildCube3up();
	void BuildCube4();
	void BuildCube4up();
	void BuildCube5();
	void BuildCube6d();
	void BuildCube6b();
	void BuildCube6kr();
	void BuildCube6kn();
	void BuildCube6a();
	void BuildCube6bout();
	void BuildCube7();
	void BuildCube7d();
	void BuildCube8();
	void BuildCube8side();
	void BuildCube8up();
	void BuildCube9();
	void BuildCube9side();
	void BuildCube10();
	void BuildCube10side();
	// Build Light
	void BuildLight();
};

