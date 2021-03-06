#include "Demo.h"

Demo::Demo() {
	shader = Shader();
	light = Light();
	camera = Camera();
}

Demo::~Demo() {
}

void Demo::Init() {
	cube = Object3D();
	cubesides = Object3D();
	cube2 = Object3D();
	cube2sides = Object3D();
	cubeup = Object3D();
	cube2up = Object3D();
	cube3 = Object3D();
	cube3up = Object3D();
	cube4 = Object3D();
	cube4up = Object3D();
	cube5 = Object3D();
	cube6b = Object3D();
	cube6bout = Object3D();
	cube6d = Object3D();
	cube6kr = Object3D();
	cube6kn = Object3D();
	cube6a = Object3D();
	cube8 = Object3D();
	cube8side = Object3D();
	cube9 = Object3D();
	cube9side = Object3D();
	cube8up = Object3D();
	cube7 = Object3D();
	cube7d = Object3D();
	plane = Object3D();
	BuildShaders();
	BuildDepthMap();
	BuildCamera();
	BuildCube();
	BuildCubesides();
	BuildCube2();
	BuildCube2sides();
	BuildCubeup();
	BuildCube2up();
	BuildCube3();
	BuildCube3up();
	BuildCube4();
	BuildCube4up();
	BuildCube5();
	BuildCube6b();
	BuildCube6bout();
	BuildCube6d();
	BuildCube6kr();
	BuildCube6kn();
	BuildCube6a();
	BuildCube7();
	BuildCube7d();
	BuildCube8();
	BuildCube8side();
	BuildCube9();
	BuildCube9side();
	BuildCube8up();
	BuildPlane();
	BuildLight();
	camera.SetDefault(true);
}

void Demo::DeInit() {
	// optional: de-allocate all resources once they've outlived their purpose:
	// ------------------------------------------------------------------------
	plane.DeInit();
	cube.DeInit();
	cubesides.DeInit();
	cube2.DeInit();
	cube2sides.DeInit();
	cubeup.DeInit();
	cube2up.DeInit();
	cube3.DeInit();
	cube3up.DeInit();
	cube4.DeInit();
	cube4up.DeInit();
	cube5.DeInit();
	cube6b.DeInit();
	cube6bout.DeInit();
	cube6d.DeInit();
	cube6kr.DeInit();
	cube6kn.DeInit();
	cube6a.DeInit();
	cube7.DeInit();
	cube7d.DeInit();
	cube8.DeInit();
	cube8side.DeInit();
	cube8up.DeInit();
	cube9.DeInit();
	cube9side.DeInit();
	glDeleteBuffers(1, &depthMapFBO);
}

// process all input: query GLFW whether relevant keys are pressed/released this frame and react accordingly
// ---------------------------------------------------------------------------------------------------------

void Demo::ProcessInput(GLFWwindow* window) {
	if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS) {
		glfwSetWindowShouldClose(window, true);
	}
}

void Demo::Update(double deltaTime) {

	// zoom camera
	// -----------
	if (glfwGetMouseButton(window, GLFW_MOUSE_BUTTON_RIGHT) == GLFW_PRESS) { // Zoom in
		if (camera.fovy < 90) {
			camera.Zoom(0.001f);
		}
	}

	if (glfwGetMouseButton(window, GLFW_MOUSE_BUTTON_LEFT) == GLFW_PRESS) { // Zoom out
		if (camera.fovy > 0) {
			camera.Zoom(-0.001f);
		}
	}

	// Move Camera
	// Move Forward n Backward
	if (glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS) { // Forward
		camera.MoveForward(0.001f);
	}
	if (glfwGetKey(window, GLFW_KEY_S) == GLFW_PRESS) { // Backward
		camera.MoveForward(-0.001f);
	}

	// Move Right n Left
	if (glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS) { // Left
		camera.MoveBeside(-0.001f);
	}

	if (glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS) { // Right
		camera.MoveBeside(0.001f);
	}

	CursorMovement();
}

void Demo::Render() {

	glEnable(GL_DEPTH_TEST);

	glClearColor(0.1f, 0.1f, 0.1f, 1.0f);

	glViewport(0, 0, this->screenWidth, this->screenHeight);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	BuildObject();

	glm::vec3 cameraPos = glm::vec3(0, -40, 0);
	glm::vec3 cameraFront = glm::vec3(0, 0, 0);

	/*GLint viewPosLoc = glGetUniformLocation(this->shadowmapShader, "viewPos");
	glUniform3f(viewPosLoc, cameraPos.x, cameraPos.y, cameraPos.z);
	glUniform3f(glGetUniformLocation(this->shadowmapShader, "dirLight.direction"), 0.0f, 40.0f, 0.0f);
	glUniform3f(glGetUniformLocation(this->shadowmapShader, "dirLight.ambient"), 10.0f, 10.0f, 10.0f);
	glUniform3f(glGetUniformLocation(this->shadowmapShader, "dirLight.diffuse"), 11.0f, 10.0f, 10.0f);
	glUniform3f(glGetUniformLocation(this->shadowmapShader, "dirLight.specular"), 10.1f, 10.1f, 10.1f);*/

	//glUniform3f(glGetUniformLocation(this->shadowmapShader, "pointLights[0].position"), 0.0f, 40.0f, 0.0f);
	//glUniform3f(glGetUniformLocation(this->shadowmapShader, "pointLights[0].ambient"), 1.0f, 0.0f, 1.0f);
	//glUniform3f(glGetUniformLocation(this->shadowmapShader, "pointLights[0].diffuse"), 1.0f, 0.0f, 0.0f);
	//glUniform3f(glGetUniformLocation(this->shadowmapShader, "pointLights[0].specular"), 1.0f, 0.0f, 0.0f);
	//glUniform1f(glGetUniformLocation(this->shadowmapShader, "pointLights[0].constant"), 1.0f);
	//glUniform1f(glGetUniformLocation(this->shadowmapShader, "pointLights[0].linear"), 0.09f);
	//glUniform1f(glGetUniformLocation(this->shadowmapShader, "pointLights[0].quadratic"), 0.032f);

	//// point light 2
	//glUniform3f(glGetUniformLocation(this->shadowmapShader, "pointLights[1].position"), 0.0f, 40.0f, 0.0f);
	//glUniform3f(glGetUniformLocation(this->shadowmapShader, "pointLights[1].ambient"), 0.0f, 1.0f, 0.0f);
	//glUniform3f(glGetUniformLocation(this->shadowmapShader, "pointLights[1].diffuse"), 0.0f, 1.0f, 0.0f);
	//glUniform3f(glGetUniformLocation(this->shadowmapShader, "pointLights[1].specular"), 0.0f, 1.0f, 0.0f);
	//glUniform1f(glGetUniformLocation(this->shadowmapShader, "pointLights[1].constant"), 1.0f);
	//glUniform1f(glGetUniformLocation(this->shadowmapShader, "pointLights[1].linear"), 0.09f);
	//glUniform1f(glGetUniformLocation(this->shadowmapShader, "pointLights[1].quadratic"), 0.032f);
	//// point light 3
	//glUniform3f(glGetUniformLocation(this->shadowmapShader, "pointLights[2].position"), 0.0f, 40.0f, 0.0f);
	//glUniform3f(glGetUniformLocation(this->shadowmapShader, "pointLights[2].ambient"), 0.0f, 0.0f, 1.0f);
	//glUniform3f(glGetUniformLocation(this->shadowmapShader, "pointLights[2].diffuse"), 0.0f, 0.0f, 1.0f);
	//glUniform3f(glGetUniformLocation(this->shadowmapShader, "pointLights[2].specular"), 0.0f, 0.0f, 1.0f);
	//glUniform1f(glGetUniformLocation(this->shadowmapShader, "pointLights[2].constant"), 1.0f);
	//glUniform1f(glGetUniformLocation(this->shadowmapShader, "pointLights[2].linear"), 0.09f);
	//glUniform1f(glGetUniformLocation(this->shadowmapShader, "pointLights[2].quadratic"), 0.032f);
	//// point light 4
	//glUniform3f(glGetUniformLocation(this->shadowmapShader, "pointLights[3].position"), 0.0f, 40.0f, 0.0f);
	//glUniform3f(glGetUniformLocation(this->shadowmapShader, "pointLights[3].ambient"), 0.0f, 1.0f, 1.0f);
	//glUniform3f(glGetUniformLocation(this->shadowmapShader, "pointLights[3].diffuse"), 0.0f, 1.0f, 1.0f);
	//glUniform3f(glGetUniformLocation(this->shadowmapShader, "pointLights[3].specular"), 0.0f, 1.0f, 1.0f);
	//glUniform1f(glGetUniformLocation(this->shadowmapShader, "pointLights[3].constant"), 1.0f);
	//glUniform1f(glGetUniformLocation(this->shadowmapShader, "pointLights[3].linear"), 0.09f);
	//glUniform1f(glGetUniformLocation(this->shadowmapShader, "pointLights[3].quadratic"), 0.032f);
	// spotLight
	/*glUniform3f(glGetUniformLocation(this->shadowmapShader, "spotLight.ambient"), 1.0f, 0.0f, 1.0f);
	glUniform3f(glGetUniformLocation(this->shadowmapShader, "spotLight.diffuse"), 1.0f, 0.0f, 1.0f);
	glUniform3f(glGetUniformLocation(this->shadowmapShader, "spotLight.specular"), 1.0f, 0.0f, 1.0f);
	glUniform1f(glGetUniformLocation(this->shadowmapShader, "spotLight.constant"), 1.0f);
	glUniform1f(glGetUniformLocation(this->shadowmapShader, "spotLight.linear"), 0.09f);
	glUniform1f(glGetUniformLocation(this->shadowmapShader, "spotLight.quadratic"), 0.032f);
	glUniform1f(glGetUniformLocation(this->shadowmapShader, "spotLight.cutOff"), glm::cos(glm::radians(12.5f)));
	glUniform1f(glGetUniformLocation(this->shadowmapShader, "spotLight.outerCutOff"), glm::cos(glm::radians(15.0f)));*/
	// Step 1 Render depth of scene to texture
	// ----------------------------------------
	/*glm::mat4 lightProjection, lightView;
	glm::mat4 lightSpaceMatrix;
	float near_plane = 1.0f, far_plane = 7.5f;
	lightProjection = glm::ortho(-10.0f, 10.0f, -10.0f, 10.0f, near_plane, far_plane);
	lightView = glm::lookAt(glm::vec3(-2.0f, 4.0f, -1.0f), glm::vec3(0.0f, 0.0f, 0.0f), glm::vec3(0.0, 1.0, 0.0));
	lightSpaceMatrix = lightProjection * lightView;*/

	// render scene from light's point of view
	/*shader.UseShader(this->depthmapShader);
	glUniformMatrix4fv(glGetUniformLocation(this->depthmapShader, "lightSpaceMatrix"), 1, GL_FALSE, glm::value_ptr(lightSpaceMatrix));
	glViewport(0, 0, this->SHADOW_WIDTH, this->SHADOW_HEIGHT);
	glBindFramebuffer(GL_FRAMEBUFFER, depthMapFBO);
	glClear(GL_DEPTH_BUFFER_BIT);*/
	//DrawTexturedCube(this->depthmapShader);
	//DrawTexturedPlane(this->depthmapShader);
	/*glBindFramebuffer(GL_FRAMEBUFFER, 0);*/



	// Step 2 Render scene normally using generated depth map
	// ------------------------------------------------------

	// Pass perspective projection matrix
	//shader.UseShader(this->shadowmapShader);
	//glm::mat4 projection = glm::perspective(45.0f, (GLfloat)this->screenWidth / (GLfloat)this->screenHeight, 0.1f, 100.0f);
	// LookAt camera (position, target/direction, up)
	/*glm::vec3 cameraPos = glm::vec3(0, 5, 2);
	glm::vec3 cameraFront = glm::vec3(0, 0, 0);*/
	//const float radius = 5.0f;
	//float camX = sin(glfwGetTime()) * radius;
	//float camZ = cos(glfwGetTime()) * radius;
	//glm::mat4 view;
	//view = glm::lookAt(glm::vec3(1.0, 50.0, 1.0), glm::vec3(0.0, -2.0, 0.0), glm::vec3(0.0, 5.0, 0.0));

	// Setting Light Attributes
	//glUniformMatrix4fv(glGetUniformLocation(this->shadowmapShader, "lightSpaceMatrix"), 1, GL_FALSE, glm::value_ptr(lightSpaceMatrix));

	// Configure Shaders


}

void Demo::CursorMovement() {
	// update camera rotation
	// ----------------------
	double mouseX, mouseY;
	double midX = screenWidth / 2;
	double midY = screenHeight / 2;
	float angleY = 0.0f;
	float angleZ = 0.0f;

	// Get mouse position
	glfwGetCursorPos(window, &mouseX, &mouseY);
	if ((mouseX == midX) && (mouseY == midY)) {
		return;
	}

	// Set mouse position
	glfwSetCursorPos(window, midX, midY);

	// Get the direction from the mouse cursor, set a resonable maneuvering speed
	angleY = (float)((midX - mouseX)) / 1000;
	angleZ = (float)((midY - mouseY)) / 1000;

	// The higher the value is the faster the camera looks around.
	camera.camDir.y += angleZ * 50;

	// limit the rotation around the x-axis
	if ((camera.camDir.y - camera.transform.position.y) > 25) {
		camera.camDir.y = camera.transform.position.y + 25;
	}
	if ((camera.camDir.y - camera.transform.position.y) < -30) {
		camera.camDir.y = camera.transform.position.y - 30;
	}

	camera.RotateCamera(-angleY);
}

void Demo::BuildObject() {
	// Render Camera
	camera.RenderCamera(this->screenWidth, this->screenHeight);
	//camera.Orbit(100.0);

	// Configurate Shader
	glUniform1i(glGetUniformLocation(this->shadowmapShader, "diffuseTexture"), 0);
	glUniform1i(glGetUniformLocation(this->shadowmapShader, "shadowMap"), 1);

	// Render light
	light.UseShader();
	glUniformMatrix4fv(glGetUniformLocation(light.GetShader(), "projection"), 1, GL_FALSE, glm::value_ptr(camera.projection));
	glUniformMatrix4fv(glGetUniformLocation(light.GetShader(), "view"), 1, GL_FALSE, glm::value_ptr(camera.view));
	glUniformMatrix4fv(glGetUniformLocation(light.GetShader(), "lightSpaceMatrix"), 1, GL_FALSE, glm::value_ptr(light.GetLightSpaceMatrix()));

	// Render floor
	plane.UseShader();
	plane.Render(depthMap);

	// Render cube
	cube.UseShader();
	cube.Render(depthMap);

	cubesides.UseShader();
	cubesides.Render(depthMap);

	cube2.UseShader();
	cube2.Render(depthMap);

	cube2sides.UseShader();
	cube2sides.Render(depthMap);

	cube3.UseShader();
	cube3.Render(depthMap);

	cube4.UseShader();
	cube4.Render(depthMap);

	cube4up.UseShader();
	cube4up.Render(depthMap);

	cube5.UseShader();
	cube5.Render(depthMap);

	cube3up.UseShader();
	cube3up.Render(depthMap);

	cube2up.UseShader();
	cube2up.Render(depthMap);

	cubeup.UseShader();
	cubeup.Render(depthMap);


	cube6b.UseShader();
	cube6b.Render(depthMap);

	cube6bout.UseShader();
	cube6bout.Render(depthMap);

	cube6d.UseShader();
	cube6d.Render(depthMap);

	cube6kr.UseShader();
	cube6kr.Render(depthMap);

	cube6kn.UseShader();
	cube6kn.Render(depthMap);

	cube6a.UseShader();
	cube6a.Render(depthMap);

	cube7.UseShader();
	cube7.Render(depthMap);

	cube7d.UseShader();
	cube7d.Render(depthMap);

	cube7d.UseShader();
	cube7d.Render(depthMap);

	cube8.UseShader();
	cube8.Render(depthMap);

	cube8side.UseShader();
	cube8side.Render(depthMap);

	cube8up.UseShader();
	cube8up.Render(depthMap);

	cube9.UseShader();
	cube9.Render(depthMap);

	cube9side.UseShader();
	cube9side.Render(depthMap);


}

void Demo::BuildCamera() {
	camera.transform.SetPosition(glm::vec3(0.0, 16.0, 0.0)); // diubah-ubah
	camera.SetCameraDirection(glm::vec3(64.0, 16.0, 0.0)); // diubah-ubah
	camera.SetCameraUp(glm::vec3(0.0, 1.0, 0.0)); // diubah-ubah
	glfwSetInputMode(this->window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);
}

void Demo::BuildLight() {
	light.SetShader(this->depthmapShader);
	light.transform.SetPosition(glm::vec3(0.0f, 39.0f, 0.0f));
	light.SetLightDir(glm::vec3(0.0f, 0.0f, 0.0f));
	light.SetLightUp(glm::vec3(0.0, 1.0, 0.0));
	light.SetFarPlane(7.5f);
	light.SetNearPlane(1.0f);
	light.CreateShadow(depthMapFBO);

	light.SetShader(this->shadowmapShader);
	light.SetLightPos(glm::vec3(0.0f, 50.0f, 0.0f));
	light.SetViewPos(glm::vec3(0.0f, 50.0f, 0.0f));
}

void Demo::BuildPlane()
{
	// Build geometry
	GLfloat vertices[] = {
		// format position, tex coords
		// bottom
		-100.0f,	-0.5f, -100.0f,  0,  0, 0.0f,  1.0f,  0.0f,
		100.0f,	-0.5f, -100.0f, 100,  0, 0.0f,  1.0f,  0.0f,
		100.0f,	-0.5f,  100.0f, 100, 100, 0.0f,  1.0f,  0.0f,
		-100.0f,	-0.5f,  100.0f,  0, 100, 0.0f,  1.0f,  0.0f,
	};

	GLuint indices[] = { 0,  2,  1,  0,  3,  2 };

	plane.SetShader(shadowmapShader);
	plane.BuildObject(vertices, sizeof(vertices), indices, sizeof(indices));

	plane.ApplyTexture("Floor.png");
	plane.VerticesDraw(sizeof(indices));
}

void Demo::BuildCube() // rak jualan 1
{
	// set up vertex data (and buffer(s)) and configure vertex attributes
	// ------------------------------------------------------------------
	float vertices[] = {
		// format position, tex coords, normal
		// front
		0.0, 0.0, 0.0, 1, 1, 0.0f,  0.0f,  1.0f, // 0
		48.0, 0.0, 0.0, 0, 1,  0.0f,  0.0f,  1.0f, // 1
		48.0,  16.0, 0.0, 0, 0,  0.0f,  0.0f,  1.0f, // 2
		0.0,  16.0, 0.0, 1, 0, 0.0f,  0.0f,  1.0f, // 3

		 // right
		 48.0,  0.0,  8.0, 1, 1, 1.0f,  0.0f,  0.0f, // 4
		 48.0,  0.0, 0.0, 0, 1, 1.0f,  0.0f,  0.0f, // 5
		 48.0, 16.0, 0.0, 0, 0, 1.0f,  0.0f,  0.0f, // 6
		 48.0, 16.0,  8.0, 1, 0, 1.0f,  0.0f,  0.0f, // 7

		// back
		0.0, 0.0, 8.0, 1, 1, 0.0f,  0.0f,  -1.0f, // 8 
		48.0,  0.0, 8.0, 0, 1, 0.0f,  0.0f,  -1.0f, // 9
		48.0,   16.0, 8.0, 0, 0, 0.0f,  0.0f,  -1.0f, // 10
		0.0,  16.0, 8.0, 1, 0, 0.0f,  0.0f,  -1.0f, // 11

		 // left
		 0.0, 0.0, 8.0, 1, 1, -1.0f,  0.0f,  0.0f, // 12
		 0.0, 0.0,  0.0, 0, 1, -1.0f,  0.0f,  0.0f, // 13
		 0.0,  16.0,  0.0, 0, 0, -1.0f,  0.0f,  0.0f, // 14
		 0.0,  16.0, 8.0, 1, 0, -1.0f,  0.0f,  0.0f, // 15

		// upper
		0.0, 16.0,  0.0, 1, 1,   0.0f,  1.0f,  0.0f, // 16
		48.0, 16.0, 0.0, 0, 1,   0.0f,  1.0f,  0.0f, // 17
		48.0, 16.0, 8.0, 0, 0,  0.0f,  1.0f,  0.0f, // 18
		0.0, 16.0, 8.0, 1, 0,   0.0f,  1.0f,  0.0f, // 19

		// bottom
		0.0, 0.0, 0.0, 1, 1, 0.0f,  -1.0f,  0.0f, // 20
		48.0, 0.0, 0.0, 0, 1,  0.0f,  -1.0f,  0.0f, // 21
		48.0, 0.0,  8.0, 0, 0,  0.0f,  -1.0f,  0.0f, // 22
		0.0, 0.0,  8.0, 1, 0, 0.0f,  -1.0f,  0.0f, // 23
	};

	unsigned int indices[] = {
		0,  1,  2,  0,  2,  3,   // front
		/*4,  5,  6,  4,  6,  7, */  // right
		8,  9,  10, 8,  10, 11 // back
		/*12, 14, 13, 12, 15, 14,*/  // left
		/*16, 18, 17, 16, 19, 18,*/  // upper
		/*20, 22, 21, 20, 23, 22 */  // bottom
	};

	cube.SetShader(shadowmapShader);
	cube.BuildObject(vertices, sizeof(vertices), indices, sizeof(indices));
	cube.ApplyTexture("rak1front.png");
	cube.VerticesDraw(sizeof(indices));
	cube.transform.SetPosition(glm::vec3( -8.0f, 0.5f, 8.0f));
	cube.transform.Scale(glm::vec3(1.0f, 1.0f, 1.0f));
}

void Demo::BuildCubesides() // rak jualan 1
{
	// set up vertex data (and buffer(s)) and configure vertex attributes
	// ------------------------------------------------------------------
	float vertices[] = {
		// format position, tex coords, normal
		// front
		0.0, 0.0, 0.0, 1, 1, 0.0f,  0.0f,  1.0f, // 0
		48.0, 0.0, 0.0, 0, 1,  0.0f,  0.0f,  1.0f, // 1
		48.0,  16.0, 0.0, 0, 0,  0.0f,  0.0f,  1.0f, // 2
		0.0,  16.0, 0.0, 1, 0, 0.0f,  0.0f,  1.0f, // 3

		 // right
		 48.0,  0.0,  8.0, 1, 1, 1.0f,  0.0f,  0.0f, // 4
		 48.0,  0.0, 0.0, 0, 1, 1.0f,  0.0f,  0.0f, // 5
		 48.0, 16.0, 0.0, 0, 0, 1.0f,  0.0f,  0.0f, // 6
		 48.0, 16.0,  8.0, 1, 0, 1.0f,  0.0f,  0.0f, // 7

		// back
		0.0, 0.0, 8.0, 1, 1, 0.0f,  0.0f,  -1.0f, // 8 
		48.0,  0.0, 8.0, 0, 1, 0.0f,  0.0f,  -1.0f, // 9
		48.0,   16.0, 8.0, 0, 0, 0.0f,  0.0f,  -1.0f, // 10
		0.0,  16.0, 8.0, 1, 0, 0.0f,  0.0f,  -1.0f, // 11

		 // left
		 0.0, 0.0, 8.0, 1, 1, -1.0f,  0.0f,  0.0f, // 12
		 0.0, 0.0,  0.0, 0, 1, -1.0f,  0.0f,  0.0f, // 13
		 0.0,  16.0,  0.0, 0, 0, -1.0f,  0.0f,  0.0f, // 14
		 0.0,  16.0, 8.0, 1, 0, -1.0f,  0.0f,  0.0f, // 15

		// upper
		0.0, 16.0,  0.0, 1, 1,   0.0f,  1.0f,  0.0f, // 16
		48.0, 16.0, 0.0, 0, 1,   0.0f,  1.0f,  0.0f, // 17
		48.0, 16.0, 8.0, 0, 0,  0.0f,  1.0f,  0.0f, // 18
		0.0, 16.0, 8.0, 1, 0,   0.0f,  1.0f,  0.0f, // 19

		// bottom
		0.0, 0.0, 0.0, 1, 1, 0.0f,  -1.0f,  0.0f, // 20
		48.0, 0.0, 0.0, 0, 1,  0.0f,  -1.0f,  0.0f, // 21
		48.0, 0.0,  8.0, 0, 0,  0.0f,  -1.0f,  0.0f, // 22
		0.0, 0.0,  8.0, 1, 0, 0.0f,  -1.0f,  0.0f, // 23
	};

	unsigned int indices[] = {
		/*0,  1,  2,  0,  2,  3,*/   // front
		4,  5,  6,  4,  6,  7,   // right
		/*8,  9,  10, 8,  10, 11,*/  // back
		12, 14, 13, 12, 15, 14,  // left
		/*16, 18, 17, 16, 19, 18,*/  // upper
		/*20, 22, 21, 20, 23, 22 */  // bottom
	};

	cubesides.SetShader(shadowmapShader);
	cubesides.BuildObject(vertices, sizeof(vertices), indices, sizeof(indices));
	cubesides.ApplyTexture("rak1sides.png");
	cubesides.VerticesDraw(sizeof(indices));
	cubesides.transform.SetPosition(glm::vec3(-8.0f, 0.5f, 8.0f));
	cubesides.transform.Scale(glm::vec3(1.0f, 1.0f, 1.0f));
}

void Demo::BuildCube8() // rak jualan 1
{
	// set up vertex data (and buffer(s)) and configure vertex attributes
	// ------------------------------------------------------------------
	float vertices[] = {
		// format position, tex coords, normal
		// front
		0.0, 0.0, 0.0, 1, 1, 0.0f,  0.0f,  1.0f, // 0
		16.0, 0.0, 0.0, 0, 1,  0.0f,  0.0f,  1.0f, // 1
		16.0,  8.0, 0.0, 0, 0,  0.0f,  0.0f,  1.0f, // 2
		0.0,  8.0, 0.0, 1, 0, 0.0f,  0.0f,  1.0f, // 3

		 // right
		 16.0,  0.0,  8.0, 1, 1, 1.0f,  0.0f,  0.0f, // 4
		 16.0,  0.0, 0.0, 0, 1, 1.0f,  0.0f,  0.0f, // 5
		 16.0, 8.0, 0.0, 0, 0, 1.0f,  0.0f,  0.0f, // 6
		 16.0, 8.0,  8.0, 1, 0, 1.0f,  0.0f,  0.0f, // 7

		// back
		0.0, 0.0, 8.0, 1, 1, 0.0f,  0.0f,  -1.0f, // 8 
		16.0,  0.0, 8.0, 0, 1, 0.0f,  0.0f,  -1.0f, // 9
		16.0,   8.0, 8.0, 0, 0, 0.0f,  0.0f,  -1.0f, // 10
		0.0,  8.0, 8.0, 1, 0, 0.0f,  0.0f,  -1.0f, // 11

		 // left
		 0.0, 0.0, 8.0, 1, 1, -1.0f,  0.0f,  0.0f, // 12
		 0.0, 0.0,  0.0, 0, 1, -1.0f,  0.0f,  0.0f, // 13
		 0.0,  8.0,  0.0, 0, 0, -1.0f,  0.0f,  0.0f, // 14
		 0.0,  8.0, 8.0, 1, 0, -1.0f,  0.0f,  0.0f, // 15

		// upper
		0.0, 8.0,  0.0, 1, 1,   0.0f,  1.0f,  0.0f, // 16
		16.0, 8.0, 0.0, 0, 1,   0.0f,  1.0f,  0.0f, // 17
		16.0, 8.0, 8.0, 0, 0,  0.0f,  1.0f,  0.0f, // 18
		0.0, 8.0, 8.0, 1, 0,   0.0f,  1.0f,  0.0f, // 19

		// bottom
		0.0, 0.0, 0.0, 1, 1, 0.0f,  -1.0f,  0.0f, // 20
		16.0, 0.0, 0.0, 0, 1,  0.0f,  -1.0f,  0.0f, // 21
		16.0, 0.0,  8.0, 0, 0,  0.0f,  -1.0f,  0.0f, // 22
		0.0, 0.0,  8.0, 1, 0, 0.0f,  -1.0f,  0.0f, // 23
	};

	unsigned int indices[] = {
		0,  1,  2,  0,  2,  3,   // front
		/*4,  5,  6,  4,  6,  7, */  // right
		8,  9,  10, 8,  10, 11 // back
		/*12, 14, 13, 12, 15, 14,*/  // left
		/*16, 18, 17, 16, 19, 18,*/  // upper
		/*20, 22, 21, 20, 23, 22 */  // bottom
	};

	cube8.SetShader(shadowmapShader);
	cube8.BuildObject(vertices, sizeof(vertices), indices, sizeof(indices));
	cube8.ApplyTexture("rakshort.png");
	cube8.VerticesDraw(sizeof(indices));
	cube8.transform.SetPosition(glm::vec3(-24.0f, 0.5f, 8.0f));
	cube8.transform.Scale(glm::vec3(1.0f, 1.0f, 1.0f));
}

void Demo::BuildCube8side() // rak jualan 1
{
	// set up vertex data (and buffer(s)) and configure vertex attributes
	// ------------------------------------------------------------------
	float vertices[] = {
		// format position, tex coords, normal
		// front
		0.0, 0.0, 0.0, 1, 1, 0.0f,  0.0f,  1.0f, // 0
		16.0, 0.0, 0.0, 0, 1,  0.0f,  0.0f,  1.0f, // 1
		16.0,  8.0, 0.0, 0, 0,  0.0f,  0.0f,  1.0f, // 2
		0.0,  8.0, 0.0, 1, 0, 0.0f,  0.0f,  1.0f, // 3

		 // right
		 16.0,  0.0,  8.0, 1, 1, 1.0f,  0.0f,  0.0f, // 4
		 16.0,  0.0, 0.0, 0, 1, 1.0f,  0.0f,  0.0f, // 5
		 16.0, 8.0, 0.0, 0, 0, 1.0f,  0.0f,  0.0f, // 6
		 16.0, 8.0,  8.0, 1, 0, 1.0f,  0.0f,  0.0f, // 7

		// back
		0.0, 0.0, 8.0, 1, 1, 0.0f,  0.0f,  -1.0f, // 8 
		16.0,  0.0, 8.0, 0, 1, 0.0f,  0.0f,  -1.0f, // 9
		16.0,   8.0, 8.0, 0, 0, 0.0f,  0.0f,  -1.0f, // 10
		0.0,  8.0, 8.0, 1, 0, 0.0f,  0.0f,  -1.0f, // 11

		 // left
		 0.0, 0.0, 8.0, 1, 1, -1.0f,  0.0f,  0.0f, // 12
		 0.0, 0.0,  0.0, 0, 1, -1.0f,  0.0f,  0.0f, // 13
		 0.0,  8.0,  0.0, 0, 0, -1.0f,  0.0f,  0.0f, // 14
		 0.0,  8.0, 8.0, 1, 0, -1.0f,  0.0f,  0.0f, // 15

		// upper
		0.0, 8.0,  0.0, 1, 1,   0.0f,  1.0f,  0.0f, // 16
		16.0, 8.0, 0.0, 0, 1,   0.0f,  1.0f,  0.0f, // 17
		16.0, 8.0, 8.0, 0, 0,  0.0f,  1.0f,  0.0f, // 18
		0.0, 8.0, 8.0, 1, 0,   0.0f,  1.0f,  0.0f, // 19

		// bottom
		0.0, 0.0, 0.0, 1, 1, 0.0f,  -1.0f,  0.0f, // 20
		16.0, 0.0, 0.0, 0, 1,  0.0f,  -1.0f,  0.0f, // 21
		16.0, 0.0,  8.0, 0, 0,  0.0f,  -1.0f,  0.0f, // 22
		0.0, 0.0,  8.0, 1, 0, 0.0f,  -1.0f,  0.0f, // 23
	};

	unsigned int indices[] = {
		/*0,  1,  2,  0,  2,  3,*/   // front
		4,  5,  6,  4,  6,  7,   // right
		/*8,  9,  10, 8,  10, 11*/ // back
		12, 14, 13, 12, 15, 14  // left
		/*16, 18, 17, 16, 19, 18,*/  // upper
		/*20, 22, 21, 20, 23, 22 */  // bottom
	};

	cube8side.SetShader(shadowmapShader);
	cube8side.BuildObject(vertices, sizeof(vertices), indices, sizeof(indices));
	cube8side.ApplyTexture("rakshortside.png");
	cube8side.VerticesDraw(sizeof(indices));
	cube8side.transform.SetPosition(glm::vec3(-24.0f, 0.5f, 8.0f));
	cube8side.transform.Scale(glm::vec3(1.0f, 1.0f, 1.0f));
}

void Demo::BuildCube8up() // rak jualan 1
{
	// set up vertex data (and buffer(s)) and configure vertex attributes
	// ------------------------------------------------------------------
	float vertices[] = {
		// format position, tex coords, normal
		// front
		0.0, 0.0, 0.0, 1, 1, 0.0f,  0.0f,  1.0f, // 0
		16.0, 0.0, 0.0, 0, 1,  0.0f,  0.0f,  1.0f, // 1
		16.0,  8.0, 0.0, 0, 0,  0.0f,  0.0f,  1.0f, // 2
		0.0,  8.0, 0.0, 1, 0, 0.0f,  0.0f,  1.0f, // 3

		 // right
		 16.0,  0.0,  8.0, 1, 1, 1.0f,  0.0f,  0.0f, // 4
		 16.0,  0.0, 0.0, 0, 1, 1.0f,  0.0f,  0.0f, // 5
		 16.0, 8.0, 0.0, 0, 0, 1.0f,  0.0f,  0.0f, // 6
		 16.0, 8.0,  8.0, 1, 0, 1.0f,  0.0f,  0.0f, // 7

		// back
		0.0, 0.0, 8.0, 1, 1, 0.0f,  0.0f,  -1.0f, // 8 
		16.0,  0.0, 8.0, 0, 1, 0.0f,  0.0f,  -1.0f, // 9
		16.0,   8.0, 8.0, 0, 0, 0.0f,  0.0f,  -1.0f, // 10
		0.0,  8.0, 8.0, 1, 0, 0.0f,  0.0f,  -1.0f, // 11

		 // left
		 0.0, 0.0, 8.0, 1, 1, -1.0f,  0.0f,  0.0f, // 12
		 0.0, 0.0,  0.0, 0, 1, -1.0f,  0.0f,  0.0f, // 13
		 0.0,  8.0,  0.0, 0, 0, -1.0f,  0.0f,  0.0f, // 14
		 0.0,  8.0, 8.0, 1, 0, -1.0f,  0.0f,  0.0f, // 15

		// upper
		0.0, 8.0,  0.0, 1, 1,   0.0f,  1.0f,  0.0f, // 16
		16.0, 8.0, 0.0, 0, 1,   0.0f,  1.0f,  0.0f, // 17
		16.0, 8.0, 8.0, 0, 0,  0.0f,  1.0f,  0.0f, // 18
		0.0, 8.0, 8.0, 1, 0,   0.0f,  1.0f,  0.0f, // 19

		// bottom
		0.0, 0.0, 0.0, 1, 1, 0.0f,  -1.0f,  0.0f, // 20
		16.0, 0.0, 0.0, 0, 1,  0.0f,  -1.0f,  0.0f, // 21
		16.0, 0.0,  8.0, 0, 0,  0.0f,  -1.0f,  0.0f, // 22
		0.0, 0.0,  8.0, 1, 0, 0.0f,  -1.0f,  0.0f, // 23
	};

	unsigned int indices[] = {
		/*0,  1,  2,  0,  2,  3,*/   // front
		/*4,  5,  6,  4,  6,  7,*/   // right
		/*8,  9,  10, 8,  10, 11*/ // back
		/*12, 14, 13, 12, 15, 14 */ // left
		16, 18, 17, 16, 19, 18 // upper
		/*20, 22, 21, 20, 23, 22 */  // bottom
	};

	cube8up.SetShader(shadowmapShader);
	cube8up.BuildObject(vertices, sizeof(vertices), indices, sizeof(indices));
	cube8up.ApplyTexture("rakshortup.png");
	cube8up.VerticesDraw(sizeof(indices));
	cube8up.transform.SetPosition(glm::vec3(-24.0f, 0.5f, 8.0f));
	cube8up.transform.Scale(glm::vec3(1.0f, 1.0f, 1.0f));
}

void Demo::BuildCube2() // rak jualan 2
{
	// set up vertex data (and buffer(s)) and configure vertex attributes
	// ------------------------------------------------------------------
	float vertices[] = {
		// format position, tex coords, normal
		// front
		0.0, 0.0, 0.0, 1, 1, 0.0f,  0.0f,  1.0f, // 0
		64.0, 0.0, 0.0, 0, 1,  0.0f,  0.0f,  1.0f, // 1
		64.0,  16.0, 0.0, 0, 0,  0.0f,  0.0f,  1.0f, // 2
		0.0,  16.0, 0.0, 1, 0, 0.0f,  0.0f,  1.0f, // 3

		 // right
		 64.0,  0.0,  8.0, 1, 1, 1.0f,  0.0f,  0.0f, // 4
		 64.0,  0.0, 0.0, 0, 1, 1.0f,  0.0f,  0.0f, // 5
		 64.0, 16.0, 0.0, 0, 0, 1.0f,  0.0f,  0.0f, // 6
		 64.0, 16.0,  8.0, 1, 0, 1.0f,  0.0f,  0.0f, // 7

		// back
		0.0, 0.0, 8.0, 1, 1, 0.0f,  0.0f,  -1.0f, // 8 
		64.0,  0.0, 8.0, 0, 1, 0.0f,  0.0f,  -1.0f, // 9
		64.0,   16.0, 8.0, 0, 0, 0.0f,  0.0f,  -1.0f, // 10
		0.0,  16.0, 8.0, 1, 0, 0.0f,  0.0f,  -1.0f, // 11

		 // left
		 0.0, 0.0, 8.0, 1, 1, -1.0f,  0.0f,  0.0f, // 12
		 0.0, 0.0,  0.0, 0, 1, -1.0f,  0.0f,  0.0f, // 13
		 0.0,  16.0,  0.0, 0, 0, -1.0f,  0.0f,  0.0f, // 14
		 0.0,  16.0, 8.0, 1, 0, -1.0f,  0.0f,  0.0f, // 15

		// upper
		0.0, 16.0,  0.0, 1, 1,   0.0f,  1.0f,  0.0f, // 16
		64.0, 16.0, 0.0, 0, 1,   0.0f,  1.0f,  0.0f, // 17
		64.0, 16.0, 8.0, 0, 0,  0.0f,  1.0f,  0.0f, // 18
		0.0, 16.0, 8.0, 1, 0,   0.0f,  1.0f,  0.0f, // 19

		// bottom
		0.0, 0.0, 0.0, 1, 1, 0.0f,  -1.0f,  0.0f, // 20
		64.0, 0.0, 0.0, 0, 1,  0.0f,  -1.0f,  0.0f, // 21
		64.0, 0.0,  8.0, 0, 0,  0.0f,  -1.0f,  0.0f, // 22
		0.0, 0.0,  8.0, 1, 0, 0.0f,  -1.0f,  0.0f, // 23
	};

	unsigned int indices[] = {
		0,  1,  2,  0,  2,  3,   // front
		/*4,  5,  6,  4,  6,  7,*/   // right
		8,  9,  10, 8,  10, 11  // back
		/*12, 14, 13, 12, 15, 14,*/  // left
		/*16, 18, 17, 16, 19, 18,*/  // upper
		/*20, 22, 21, 20, 23, 22*/   // bottom
	};

	cube2.SetShader(shadowmapShader);
	cube2.BuildObject(vertices, sizeof(vertices), indices, sizeof(indices));
	cube2.ApplyTexture("rak_beta.png");
	cube2.VerticesDraw(sizeof(indices));
	cube2.transform.SetPosition(glm::vec3(-24.0f, 0.5f, -16.0f));
	cube2.transform.Scale(glm::vec3(1.0f, 1.0f, 1.0f));
}

void Demo::BuildCube2sides() // rak jualan 2
{
	// set up vertex data (and buffer(s)) and configure vertex attributes
	// ------------------------------------------------------------------
	float vertices[] = {
		// format position, tex coords, normal
		// front
		0.0, 0.0, 0.0, 1, 1, 0.0f,  0.0f,  1.0f, // 0
		64.0, 0.0, 0.0, 0, 1,  0.0f,  0.0f,  1.0f, // 1
		64.0,  16.0, 0.0, 0, 0,  0.0f,  0.0f,  1.0f, // 2
		0.0,  16.0, 0.0, 1, 0, 0.0f,  0.0f,  1.0f, // 3

		 // right
		 64.0,  0.0,  8.0, 1, 1, 1.0f,  0.0f,  0.0f, // 4
		 64.0,  0.0, 0.0, 0, 1, 1.0f,  0.0f,  0.0f, // 5
		 64.0, 16.0, 0.0, 0, 0, 1.0f,  0.0f,  0.0f, // 6
		 64.0, 16.0,  8.0, 1, 0, 1.0f,  0.0f,  0.0f, // 7

		// back
		0.0, 0.0, 8.0, 1, 1, 0.0f,  0.0f,  -1.0f, // 8 
		64.0,  0.0, 8.0, 0, 1, 0.0f,  0.0f,  -1.0f, // 9
		64.0,   16.0, 8.0, 0, 0, 0.0f,  0.0f,  -1.0f, // 10
		0.0,  16.0, 8.0, 1, 0, 0.0f,  0.0f,  -1.0f, // 11

		 // left
		 0.0, 0.0, 8.0, 1, 1, -1.0f,  0.0f,  0.0f, // 12
		 0.0, 0.0,  0.0, 0, 1, -1.0f,  0.0f,  0.0f, // 13
		 0.0,  16.0,  0.0, 0, 0, -1.0f,  0.0f,  0.0f, // 14
		 0.0,  16.0, 8.0, 1, 0, -1.0f,  0.0f,  0.0f, // 15

		// upper
		0.0, 16.0,  0.0, 1, 1,   0.0f,  1.0f,  0.0f, // 16
		64.0, 16.0, 0.0, 0, 1,   0.0f,  1.0f,  0.0f, // 17
		64.0, 16.0, 8.0, 0, 0,  0.0f,  1.0f,  0.0f, // 18
		0.0, 16.0, 8.0, 1, 0,   0.0f,  1.0f,  0.0f, // 19

		// bottom
		0.0, 0.0, 0.0, 1, 1, 0.0f,  -1.0f,  0.0f, // 20
		64.0, 0.0, 0.0, 0, 1,  0.0f,  -1.0f,  0.0f, // 21
		64.0, 0.0,  8.0, 0, 0,  0.0f,  -1.0f,  0.0f, // 22
		0.0, 0.0,  8.0, 1, 0, 0.0f,  -1.0f,  0.0f, // 23
	};

	unsigned int indices[] = {
		/*0,  1,  2,  0,  2,  3, */  // front
		4,  5,  6,  4,  6,  7,   // right
		/*8,  9,  10, 8,  10, 11,*/  // back
		12, 14, 13, 12, 15, 14  // left
		/*16, 18, 17, 16, 19, 18,*/  // upper
		/*20, 22, 21, 20, 23, 22  */ // bottom
	};

	cube2sides.SetShader(shadowmapShader);
	cube2sides.BuildObject(vertices, sizeof(vertices), indices, sizeof(indices));
	cube2sides.ApplyTexture("raksides.png");
	cube2sides.VerticesDraw(sizeof(indices));
	cube2sides.transform.SetPosition(glm::vec3(-24.0f, 0.5f, -16.0f));
	cube2sides.transform.Scale(glm::vec3(1.0f, 1.0f, 1.0f));
}

void Demo::BuildCubeup() //rak jualan 1
{
	// set up vertex data (and buffer(s)) and configure vertex attributes
	// ------------------------------------------------------------------
	float vertices[] = {
		// format position, tex coords, normal
		// front
		0.0, 0.0, 0.0, 0, 0, 0.0f,  0.0f,  1.0f, // 0
		48.0, 0.0, 0.0, 1, 0,  0.0f,  0.0f,  1.0f, // 1
		48.0,  16.0, 0.0, 1, 1,  0.0f,  0.0f,  1.0f, // 2
		0.0,  16.0, 0.0, 0, 1, 0.0f,  0.0f,  1.0f, // 3

		 // right
		 48.0,  0.0,  8.0, 0, 0, 1.0f,  0.0f,  0.0f, // 4
		 48.0,  0.0, 0.0, 1, 0, 1.0f,  0.0f,  0.0f, // 5
		 48.0, 16.0, 0.0, 1, 1, 1.0f,  0.0f,  0.0f, // 6
		 48.0, 16.0,  8.0, 0, 1, 1.0f,  0.0f,  0.0f, // 7

		// back
		0.0, 0.0, 8.0, 0, 0, 0.0f,  0.0f,  -1.0f, // 8 
		48.0,  0.0, 8.0, 1, 0, 0.0f,  0.0f,  -1.0f, // 9
		48.0,   16.0, 8.0, 1, 1, 0.0f,  0.0f,  -1.0f, // 10
		0.0,  16.0, 8.0, 0, 1, 0.0f,  0.0f,  -1.0f, // 11

		 // left
		 0.0, 0.0, 8.0, 0, 0, -1.0f,  0.0f,  0.0f, // 12
		 0.0, 0.0,  0.0, 1, 0, -1.0f,  0.0f,  0.0f, // 13
		 0.0,  16.0,  0.0, 1, 1, -1.0f,  0.0f,  0.0f, // 14
		 0.0,  16.0, 8.0, 0, 1, -1.0f,  0.0f,  0.0f, // 15

		// upper
		0.0, 16.0,  0.0, 0, 0,   0.0f,  1.0f,  0.0f, // 16
		48.0, 16.0, 0.0, 1, 0,   0.0f,  1.0f,  0.0f, // 17
		48.0, 16.0, 8.0, 1, 1,  0.0f,  1.0f,  0.0f, // 18
		0.0, 16.0, 8.0, 0, 1,   0.0f,  1.0f,  0.0f, // 19

		// bottom
		0.0, 0.0, 0.0, 0, 0, 0.0f,  -1.0f,  0.0f, // 20
		48.0, 0.0, 0.0, 1, 0,  0.0f,  -1.0f,  0.0f, // 21
		48.0, 0.0,  8.0, 1, 1,  0.0f,  -1.0f,  0.0f, // 22
		0.0, 0.0,  8.0, 0, 1, 0.0f,  -1.0f,  0.0f, // 23
	};

	unsigned int indices[] = {
		//0,  1,  2,  0,  2,  3,  // front
		//4,  5,  6,  4,  6,  7,   // right
		//8,  9,  10, 8,  10, 11,  // back
		//12, 14, 13, 12, 15, 14,  // left
		16, 18, 17, 16, 19, 18 // upper
		/*20, 22, 21, 20, 23, 22 */  // bottom
	};

	cubeup.SetShader(shadowmapShader);
	cubeup.BuildObject(vertices, sizeof(vertices), indices, sizeof(indices));
	cubeup.ApplyTexture("Rakup.png");
	cubeup.VerticesDraw(sizeof(indices));
	cubeup.transform.SetPosition(glm::vec3(-8.0f, 0.5f, 8.0f));
	cubeup.transform.Scale(glm::vec3(1.0f, 1.0f, 1.0f));
}

void Demo::BuildCube2up() // rak jualan 2
{
	// set up vertex data (and buffer(s)) and configure vertex attributes
	// ------------------------------------------------------------------
	float vertices[] = {
		// format position, tex coords, normal
		// front
		0.0, 0.0, 0.0, 0, 0, 0.0f,  0.0f,  1.0f, // 0
		64.0, 0.0, 0.0, 1, 0,  0.0f,  0.0f,  1.0f, // 1
		64.0,  16.0, 0.0, 1, 1,  0.0f,  0.0f,  1.0f, // 2
		0.0,  16.0, 0.0, 0, 1, 0.0f,  0.0f,  1.0f, // 3

		 // right
		 64.0,  0.0,  8.0, 0, 0, 1.0f,  0.0f,  0.0f, // 4
		 64.0,  0.0, 0.0, 1, 0, 1.0f,  0.0f,  0.0f, // 5
		 64.0, 16.0, 0.0, 1, 1, 1.0f,  0.0f,  0.0f, // 6
		 64.0, 16.0,  8.0, 0, 1, 1.0f,  0.0f,  0.0f, // 7

		// back
		0.0, 0.0, 8.0, 0, 0, 0.0f,  0.0f,  -1.0f, // 8 
		64.0,  0.0, 8.0, 1, 0, 0.0f,  0.0f,  -1.0f, // 9
		64.0,   16.0, 8.0, 1, 1, 0.0f,  0.0f,  -1.0f, // 10
		0.0,  16.0, 8.0, 0, 1, 0.0f,  0.0f,  -1.0f, // 11

		 // left
		 0.0, 0.0, 8.0, 0, 0, -1.0f,  0.0f,  0.0f, // 12
		 0.0, 0.0,  0.0, 1, 0, -1.0f,  0.0f,  0.0f, // 13
		 0.0,  16.0,  0.0, 1, 1, -1.0f,  0.0f,  0.0f, // 14
		 0.0,  16.0, 8.0, 0, 1, -1.0f,  0.0f,  0.0f, // 15

		// upper
		0.0, 16.0,  0.0, 0, 0,   0.0f,  1.0f,  0.0f, // 16
		64.0, 16.0, 0.0, 1, 0,   0.0f,  1.0f,  0.0f, // 17
		64.0, 16.0, 8.0, 1, 1,  0.0f,  1.0f,  0.0f, // 18
		0.0, 16.0, 8.0, 0, 1,   0.0f,  1.0f,  0.0f, // 19

		// bottom
		0.0, 0.0, 0.0, 0, 0, 0.0f,  -1.0f,  0.0f, // 20
		64.0, 0.0, 0.0, 1, 0,  0.0f,  -1.0f,  0.0f, // 21
		64.0, 0.0,  8.0, 1, 1,  0.0f,  -1.0f,  0.0f, // 22
		0.0, 0.0,  8.0, 0, 1, 0.0f,  -1.0f,  0.0f, // 23
	};

	unsigned int indices[] = {
		//0,  1,  2,  0,  2,  3,   // front
		//4,  5,  6,  4,  6,  7,   // right
		//8,  9,  10, 8,  10, 11,  // back
		//12, 14, 13, 12, 15, 14,  // left
		16, 18, 17, 16, 19, 18  // upper
		/*20, 22, 21, 20, 23, 22 */  // bottom
	};

	cube2up.SetShader(shadowmapShader);
	cube2up.BuildObject(vertices, sizeof(vertices), indices, sizeof(indices));
	cube2up.ApplyTexture("Rakup.png");
	cube2up.VerticesDraw(sizeof(indices));
	cube2up.transform.SetPosition(glm::vec3(-24.0f, 0.5f, -16.0f));
	cube2up.transform.Scale(glm::vec3(1.0f, 1.0f, 1.0f));
}

void Demo::BuildCube3() // kulkas
{
	// set up vertex data (and buffer(s)) and configure vertex attributes
	// ------------------------------------------------------------------
	float vertices[] = {
		// format position, tex coords, normal
		// front
		0.0, 0.0, 0.0, 0, 0, 0.0f,  0.0f,  1.0f, // 0
		8.0, 0.0, 0.0, 1, 0,  0.0f,  0.0f,  1.0f, // 1
		8.0,  16.0, 0.0, 1, 1,  0.0f,  0.0f,  1.0f, // 2
		0.0,  16.0, 0.0, 0, 1, 0.0f,  0.0f,  1.0f, // 3

		 // right
		 8.0,  0.0,  0.0, 0, 0, 1.0f,  0.0f,  0.0f, // 4
		 8.0,  0.0, 64.0, 1, 0, 1.0f,  0.0f,  0.0f, // 5
		 8.0, 16.0, 64.0, 1, 1, 1.0f,  0.0f,  0.0f, // 6
		 8.0, 16.0,  0.0, 0, 1, 1.0f,  0.0f,  0.0f, // 7

		// back
		0.0, 0.0, 64.0, 0, 0, 0.0f,  0.0f,  -1.0f, // 8 
		8.0,  0.0, 64.0, 1, 0, 0.0f,  0.0f,  -1.0f, // 9
		8.0,   16.0, 64.0, 1, 1, 0.0f,  0.0f,  -1.0f, // 10
		0.0,  16.0, 64.0, 0, 1, 0.0f,  0.0f,  -1.0f, // 11

		 // left
		 0.0, 0.0, 64.0, 0, 1, -1.0f,  0.0f,  0.0f, // 12
		 0.0, 0.0,  0.0, 1, 1, -1.0f,  0.0f,  0.0f, // 13
		 0.0,  16.0,  0.0, 1, 0, -1.0f,  0.0f,  0.0f, // 14
		 0.0,  16.0, 64.0, 0, 0, -1.0f,  0.0f,  0.0f, // 15

		// upper
		0.0, 16.0,  0.0, 0, 0,   0.0f,  1.0f,  0.0f, // 16
		8.0, 16.0, 0.0, 1, 0,   0.0f,  1.0f,  0.0f, // 17
		8.0, 16.0, 64.0, 1, 1,  0.0f,  1.0f,  0.0f, // 18
		0.0, 16.0, 64.0, 0, 1,   0.0f,  1.0f,  0.0f, // 19

		// bottom
		0.0, 0.0, 0.0, 0, 0, 0.0f,  -1.0f,  0.0f, // 20
		8.0, 0.0, 0.0, 1, 0,  0.0f,  -1.0f,  0.0f, // 21
		8.0, 0.0,  64.0, 1, 1,  0.0f,  -1.0f,  0.0f, // 22
		0.0, 0.0,  64.0, 0, 1, 0.0f,  -1.0f,  0.0f, // 23
	};

	unsigned int indices[] = {
		/*0,  1,  2,  0,  2,  3, */  // front
		/*4,  5,  6,  4,  6,  7 */ // right
		//8,  9,  10, 8,  10, 11,  // back
		12, 14, 13, 12, 15, 14,  // left
		//16, 18, 17, 16, 19, 18,  // upper
		//20, 22, 21, 20, 23, 22   // bottom
	};

	cube3.SetShader(shadowmapShader);
	cube3.BuildObject(vertices, sizeof(vertices), indices, sizeof(indices));

	cube3.ApplyTexture("Kulkas.png");
	cube3.VerticesDraw(sizeof(indices));
	cube3.transform.SetPosition(glm::vec3(64.0f, 0.5f, -32.0f));
	cube3.transform.Scale(glm::vec3(1.0f, 1.0f, 1.0f));
}

void Demo::BuildCube3up() // kulkas
{
	// set up vertex data (and buffer(s)) and configure vertex attributes
	// ------------------------------------------------------------------
	float vertices[] = {
		// format position, tex coords, normal
		// front
		0.0, 0.0, 0.0, 0, 0, 0.0f,  0.0f,  1.0f, // 0
		8.0, 0.0, 0.0, 1, 0,  0.0f,  0.0f,  1.0f, // 1
		8.0,  16.0, 0.0, 1, 1,  0.0f,  0.0f,  1.0f, // 2
		0.0,  16.0, 0.0, 0, 1, 0.0f,  0.0f,  1.0f, // 3

		 // right
		 8.0,  0.0,  0.0, 0, 0, 1.0f,  0.0f,  0.0f, // 4
		 8.0,  0.0, 64.0, 1, 0, 1.0f,  0.0f,  0.0f, // 5
		 8.0, 16.0, 64.0, 1, 1, 1.0f,  0.0f,  0.0f, // 6
		 8.0, 16.0,  0.0, 0, 1, 1.0f,  0.0f,  0.0f, // 7

		// back
		0.0, 0.0, 64.0, 0, 0, 0.0f,  0.0f,  -1.0f, // 8 
		8.0,  0.0, 64.0, 1, 0, 0.0f,  0.0f,  -1.0f, // 9
		8.0,   16.0, 64.0, 1, 1, 0.0f,  0.0f,  -1.0f, // 10
		0.0,  16.0, 64.0, 0, 1, 0.0f,  0.0f,  -1.0f, // 11

		 // left
		 0.0, 0.0, 64.0, 0, 0, -1.0f,  0.0f,  0.0f, // 12
		 0.0, 0.0,  0.0, 1, 0, -1.0f,  0.0f,  0.0f, // 13
		 0.0,  16.0,  0.0, 1, 1, -1.0f,  0.0f,  0.0f, // 14
		 0.0,  16.0, 64.0, 0, 1, -1.0f,  0.0f,  0.0f, // 15

		// upper
		0.0, 16.0,  0.0, 0, 0,   0.0f,  1.0f,  0.0f, // 16
		8.0, 16.0, 0.0, 1, 0,   0.0f,  1.0f,  0.0f, // 17
		8.0, 16.0, 64.0, 1, 1,  0.0f,  1.0f,  0.0f, // 18
		0.0, 16.0, 64.0, 0, 1,   0.0f,  1.0f,  0.0f, // 19

		// bottom
		0.0, 0.0, 0.0, 0, 0, 0.0f,  -1.0f,  0.0f, // 20
		8.0, 0.0, 0.0, 1, 0,  0.0f,  -1.0f,  0.0f, // 21
		8.0, 0.0,  64.0, 1, 1,  0.0f,  -1.0f,  0.0f, // 22
		0.0, 0.0,  64.0, 0, 1, 0.0f,  -1.0f,  0.0f, // 23
	};

	unsigned int indices[] = {
		/*0,  1,  2,  0,  2,  3,  */ // front
		/*4,  5,  6,  4,  6,  7,*/   // right
		/*8,  9,  10, 8,  10, 11,*/  // back
		/*12, 14, 13, 12, 15, 14,*/  // left
		16, 18, 17, 16, 19, 18// upper
		/*20, 22, 21, 20, 23, 22*/   // bottom
	};

	cube3up.SetShader(shadowmapShader);
	cube3up.BuildObject(vertices, sizeof(vertices), indices, sizeof(indices));
	cube3up.ApplyTexture("Kulkasside.png");
	cube3up.VerticesDraw(sizeof(indices));
	cube3up.transform.SetPosition(glm::vec3(64.0f, 0.5f, -32.0f));
	cube3up.transform.Scale(glm::vec3(1.0f, 1.0f, 1.0f));
}

void Demo::BuildCube4() // rak kecil
{
	// set up vertex data (and buffer(s)) and configure vertex attributes
	// ------------------------------------------------------------------
	float vertices[] = {
		// format position, tex coords, normal
		// front
		0.0, 0.0, 0.0, 0, 0, 0.0f,  0.0f,  1.0f, // 0
		8.0, 0.0, 0.0, 1, 0,  0.0f,  0.0f,  1.0f, // 1
		8.0,  16.0, 0.0, 1, 1,  0.0f,  0.0f,  1.0f, // 2
		0.0,  16.0, 0.0, 0, 1, 0.0f,  0.0f,  1.0f, // 3

		 // right
		 8.0,  0.0,  0.0, 0, 0, 1.0f,  0.0f,  0.0f, // 4
		 8.0,  0.0, 8.0, 1, 0, 1.0f,  0.0f,  0.0f, // 5
		 8.0, 16.0, 8.0, 1, 1, 1.0f,  0.0f,  0.0f, // 6
		 8.0, 16.0,  0.0, 0, 1, 1.0f,  0.0f,  0.0f, // 7

		// back
		0.0, 0.0, 8.0, 0, 0, 0.0f,  0.0f,  -1.0f, // 8 
		8.0,  0.0, 8.0, 1, 0, 0.0f,  0.0f,  -1.0f, // 9
		8.0,   16.0, 8.0, 1, 1, 0.0f,  0.0f,  -1.0f, // 10
		0.0,  16.0, 8.0, 0, 1, 0.0f,  0.0f,  -1.0f, // 11

		 // left
		 0.0, 0.0, 8.0, 0, 0, -1.0f,  0.0f,  0.0f, // 12
		 0.0, 0.0,  0.0, 1, 0, -1.0f,  0.0f,  0.0f, // 13
		 0.0,  16.0,  0.0, 1, 1, -1.0f,  0.0f,  0.0f, // 14
		 0.0,  16.0, 8.0, 0, 1, -1.0f,  0.0f,  0.0f, // 15

		// upper
		0.0, 16.0,  0.0, 0, 0,   0.0f,  1.0f,  0.0f, // 16
		8.0, 16.0, 0.0, 1, 0,   0.0f,  1.0f,  0.0f, // 17
		8.0, 16.0, 8.0, 1, 1,  0.0f,  1.0f,  0.0f, // 18
		0.0, 16.0, 8.0, 0, 1,   0.0f,  1.0f,  0.0f, // 19

		// bottom
		0.0, 0.0, 0.0, 0, 0, 0.0f,  -1.0f,  0.0f, // 20
		8.0, 0.0, 0.0, 1, 0,  0.0f,  -1.0f,  0.0f, // 21
		8.0, 0.0,  8.0, 1, 1,  0.0f,  -1.0f,  0.0f, // 22
		0.0, 0.0,  8.0, 0, 1, 0.0f,  -1.0f,  0.0f, // 23
	};

	unsigned int indices[] = {
		0,  1,  2,  0,  2,  3,   // front
		4,  5,  6,  4,  6,  7,   // right
		8,  9,  10, 8,  10, 11,  // back
		12, 14, 13, 12, 15, 14,  // left
		/*16, 18, 17, 16, 19, 18, */ // upper
		20, 22, 21, 20, 23, 22   // bottom
	};

	cube4.SetShader(shadowmapShader);
	cube4.BuildObject(vertices, sizeof(vertices), indices, sizeof(indices));

	cube4.ApplyTexture("magazinerack.png");
	cube4.VerticesDraw(sizeof(indices));
	cube4.transform.SetPosition(glm::vec3(-48.0f, 0.5f, -8.0f));
	cube4.transform.Scale(glm::vec3(1.0f, 1.0f, 1.0f));
}

void Demo::BuildCube4up() // rak kecil
{
	// set up vertex data (and buffer(s)) and configure vertex attributes
	// ------------------------------------------------------------------
	float vertices[] = {
		// format position, tex coords, normal
		// front
		0.0, 0.0, 0.0, 0, 0, 0.0f,  0.0f,  1.0f, // 0
		8.0, 0.0, 0.0, 1, 0,  0.0f,  0.0f,  1.0f, // 1
		8.0,  16.0, 0.0, 1, 1,  0.0f,  0.0f,  1.0f, // 2
		0.0,  16.0, 0.0, 0, 1, 0.0f,  0.0f,  1.0f, // 3

		 // right
		 8.0,  0.0,  0.0, 0, 0, 1.0f,  0.0f,  0.0f, // 4
		 8.0,  0.0, 8.0, 1, 0, 1.0f,  0.0f,  0.0f, // 5
		 8.0, 16.0, 8.0, 1, 1, 1.0f,  0.0f,  0.0f, // 6
		 8.0, 16.0,  0.0, 0, 1, 1.0f,  0.0f,  0.0f, // 7

		// back
		0.0, 0.0, 8.0, 0, 0, 0.0f,  0.0f,  -1.0f, // 8 
		8.0,  0.0, 8.0, 1, 0, 0.0f,  0.0f,  -1.0f, // 9
		8.0,   16.0, 8.0, 1, 1, 0.0f,  0.0f,  -1.0f, // 10
		0.0,  16.0, 8.0, 0, 1, 0.0f,  0.0f,  -1.0f, // 11

		 // left
		 0.0, 0.0, 8.0, 0, 0, -1.0f,  0.0f,  0.0f, // 12
		 0.0, 0.0,  0.0, 1, 0, -1.0f,  0.0f,  0.0f, // 13
		 0.0,  16.0,  0.0, 1, 1, -1.0f,  0.0f,  0.0f, // 14
		 0.0,  16.0, 8.0, 0, 1, -1.0f,  0.0f,  0.0f, // 15

		// upper
		0.0, 16.0,  0.0, 0, 0,   0.0f,  1.0f,  0.0f, // 16
		8.0, 16.0, 0.0, 1, 0,   0.0f,  1.0f,  0.0f, // 17
		8.0, 16.0, 8.0, 1, 1,  0.0f,  1.0f,  0.0f, // 18
		0.0, 16.0, 8.0, 0, 1,   0.0f,  1.0f,  0.0f, // 19

		// bottom
		0.0, 0.0, 0.0, 0, 0, 0.0f,  -1.0f,  0.0f, // 20
		8.0, 0.0, 0.0, 1, 0,  0.0f,  -1.0f,  0.0f, // 21
		8.0, 0.0,  8.0, 1, 1,  0.0f,  -1.0f,  0.0f, // 22
		0.0, 0.0,  8.0, 0, 1, 0.0f,  -1.0f,  0.0f, // 23
	};

	unsigned int indices[] = {
		//0,  1,  2,  0,  2,  3,   // front
		//4,  5,  6,  4,  6,  7,   // right
		//8,  9,  10, 8,  10, 11,  // back
		//12, 14, 13, 12, 15, 14,  // left
		16, 18, 17, 16, 19, 18 // upper
		/*20, 22, 21, 20, 23, 22 */  // bottom
	};

	cube4up.SetShader(shadowmapShader);
	cube4up.BuildObject(vertices, sizeof(vertices), indices, sizeof(indices));

	cube4up.ApplyTexture("Wood.png");
	cube4up.VerticesDraw(sizeof(indices));
	cube4up.transform.SetPosition(glm::vec3(-48.0f, 0.5f, -8.0f));
	cube4up.transform.Scale(glm::vec3(1.0f, 1.0f, 1.0f));
}

void Demo::BuildCube5() //kasir
{
	// set up vertex data (and buffer(s)) and configure vertex attributes
	// ------------------------------------------------------------------
	float vertices[] = {
		// format position, tex coords, normal
		// front
		0.0, 0.0, 0.0, 0, 0, 0.0f,  0.0f,  1.0f, // 0
		8.0, 0.0, 0.0, 1, 0,  0.0f,  0.0f,  1.0f, // 1
		8.0,  4.0, 0.0, 1, 1,  0.0f,  0.0f,  1.0f, // 2
		0.0,  4.0, 0.0, 0, 1, 0.0f,  0.0f,  1.0f, // 3

		 // right
		 8.0,  0.0,  0.0, 0, 0, 1.0f,  0.0f,  0.0f, // 4
		 8.0,  0.0, 32.0, 1, 0, 1.0f,  0.0f,  0.0f, // 5
		 8.0, 4.0, 32.0, 1, 1, 1.0f,  0.0f,  0.0f, // 6
		 8.0, 4.0,  0.0, 0, 1, 1.0f,  0.0f,  0.0f, // 7

		// back
		0.0, 0.0, 32.0, 0, 0, 0.0f,  0.0f,  -1.0f, // 8 
		8.0,  0.0, 32.0, 1, 0, 0.0f,  0.0f,  -1.0f, // 9
		8.0,   4.0, 32.0, 1, 1, 0.0f,  0.0f,  -1.0f, // 10
		0.0,  4.0, 32.0, 0, 1, 0.0f,  0.0f,  -1.0f, // 11

		 // left
		 0.0, 0.0, 32.0, 0, 0, -1.0f,  0.0f,  0.0f, // 12
		 0.0, 0.0,  0.0, 1, 0, -1.0f,  0.0f,  0.0f, // 13
		 0.0,  4.0,  0.0, 1, 1, -1.0f,  0.0f,  0.0f, // 14
		 0.0,  4.0, 32.0, 0, 1, -1.0f,  0.0f,  0.0f, // 15

		// upper
		0.0, 4.0,  0.0, 0, 0,   0.0f,  1.0f,  0.0f, // 16
		8.0, 4.0, 0.0, 1, 0,   0.0f,  1.0f,  0.0f, // 17
		8.0, 4.0, 32.0, 1, 1,  0.0f,  1.0f,  0.0f, // 18
		0.0, 4.0, 32.0, 0, 1,   0.0f,  1.0f,  0.0f, // 19

		// bottom
		0.0, 0.0, 0.0, 0, 0, 0.0f,  -1.0f,  0.0f, // 20
		8.0, 0.0, 0.0, 1, 0,  0.0f,  -1.0f,  0.0f, // 21
		8.0, 0.0,  32.0, 1, 1,  0.0f,  -1.0f,  0.0f, // 22
		0.0, 0.0,  32.0, 0, 1, 0.0f,  -1.0f,  0.0f, // 23
	};

	unsigned int indices[] = {
		0,  1,  2,  0,  2,  3,   // front
		4,  5,  6,  4,  6,  7,   // right
		8,  9,  10, 8,  10, 11,  // back
		12, 14, 13, 12, 15, 14,  // left
		16, 18, 17, 16, 19, 18,  // upper
		20, 22, 21, 20, 23, 22   // bottom
	};

	cube5.SetShader(shadowmapShader);
	cube5.BuildObject(vertices, sizeof(vertices), indices, sizeof(indices));

	cube5.ApplyTexture("Kasir.png");
	cube5.VerticesDraw(sizeof(indices));
	cube5.transform.SetPosition(glm::vec3(-48.0f, 4.0f, 0.0f));
	cube5.transform.Scale(glm::vec3(1.0f, 1.0f, 1.0f));
}

void Demo::BuildCube6d() //ruangannya jadi b
{
	// set up vertex data (and buffer(s)) and configure vertex attributes
	// ------------------------------------------------------------------
	float vertices[] = {
		// format position, tex coords, normal
		// front
		0.0, 0.0, 0.0, 1, 1, 0.0f,  0.0f,  1.0f, // 0
		128.0, 0.0, 0.0, 0, 1,  0.0f,  0.0f,  1.0f, // 1
		128.0,  40.0, 0.0, 0, 0,  0.0f,  0.0f,  1.0f, // 2
		0.0,  40.0, 0.0, 1, 0, 0.0f,  0.0f,  1.0f, // 3

		 // right
		 128.0,  0.0,  0.0, 0, 0, 1.0f,  0.0f,  0.0f, // 4
		 128.0,  0.0, 64.0, 1, 0, 1.0f,  0.0f,  0.0f, // 5
		 128.0, 40.0, 64.0, 1, 1, 1.0f,  0.0f,  0.0f, // 6
		 128.0, 40.0,  0.0, 0, 1, 1.0f,  0.0f,  0.0f, // 7

		// back
		0.0, 0.0, 64.0, 0, 0, 0.0f,  0.0f,  -1.0f, // 8 
		128.0,  0.0, 64.0, 1, 0, 0.0f,  0.0f,  -1.0f, // 9
		128.0,   40.0, 64.0, 1, 1, 0.0f,  0.0f,  -1.0f, // 10
		0.0,  40.0, 64.0, 0, 1, 0.0f,  0.0f,  -1.0f, // 11

		 // left
		 0.0, 0.0, 64.0, 0, 0, -1.0f,  0.0f,  0.0f, // 12
		 0.0, 0.0,  0.0, 1, 0, -1.0f,  0.0f,  0.0f, // 13
		 0.0,  40.0,  0.0, 1, 1, -1.0f,  0.0f,  0.0f, // 14
		 0.0,  40.0, 64.0, 0, 1, -1.0f,  0.0f,  0.0f, // 15

		// upper
		0.0, 40.0,  0.0, 0, 0,   0.0f,  1.0f,  0.0f, // 16
		128.0, 40.0, 0.0, 1, 0,   0.0f,  1.0f,  0.0f, // 17
		128.0, 40.0, 64.0, 1, 1,  0.0f,  1.0f,  0.0f, // 18
		0.0, 40.0, 64.0, 0, 1,   0.0f,  1.0f,  0.0f, // 19

		// bottom
		0.0, 0.0, 0.0, 0, 0, 0.0f,  -1.0f,  0.0f, // 20
		128.0, 0.0, 0.0, 1, 0,  0.0f,  -1.0f,  0.0f, // 21
		128.0, 0.0,  64.0, 1, 1,  0.0f,  -1.0f,  0.0f, // 22
		0.0, 0.0,  64.0, 0, 1, 0.0f,  -1.0f,  0.0f, // 23
	};

	unsigned int indices[] = {
		0,  1,  2,  0,  2,  3,   // front
		//4,  5,  6,  4,  6,  7,   // right
		//8,  9,  10, 8,  10, 11,  // back
		//12, 14, 13, 12, 15, 14,  // left
		//16, 18, 17, 16, 19, 18,  // upper
		//20, 22, 21, 20, 23, 22   // bottom
	};

	cube6d.SetShader(shadowmapShader);
	cube6d.BuildObject(vertices, sizeof(vertices), indices, sizeof(indices));

	cube6d.ApplyTexture("tembok_b.png");
	cube6d.VerticesDraw(sizeof(indices));
	cube6d.transform.SetPosition(glm::vec3(-56.0f, 0.0f, -32.0f));
	cube6d.transform.Scale(glm::vec3(1.0f, 1.0f, 1.0f));
}

void Demo::BuildCube6b() //ruangannya jadi d
{
	// set up vertex data (and buffer(s)) and configure vertex attributes
	// ------------------------------------------------------------------
	float vertices[] = {
		// format position, tex coords, normal
		// front
		0.0, 0.0, 0.0, 0, 0, 0.0f,  0.0f,  1.0f, // 0
		128.0, 0.0, 0.0, 1, 0,  0.0f,  0.0f,  1.0f, // 1
		128.0,  40.0, 0.0, 1, 1,  0.0f,  0.0f,  1.0f, // 2
		0.0,  40.0, 0.0, 0, 1, 0.0f,  0.0f,  1.0f, // 3

		 // right
		 128.0,  0.0,  0.0, 0, 0, 1.0f,  0.0f,  0.0f, // 4
		 128.0,  0.0, 64.0, 1, 0, 1.0f,  0.0f,  0.0f, // 5
		 128.0, 40.0, 64.0, 1, 1, 1.0f,  0.0f,  0.0f, // 6
		 128.0, 40.0,  0.0, 0, 1, 1.0f,  0.0f,  0.0f, // 7

		// back
		0.0, 0.0, 64.0, 1, 1, 0.0f,  0.0f,  -1.0f, // 8 
		128.0,  0.0, 64.0, 0, 1, 0.0f,  0.0f,  -1.0f, // 9
		128.0,   40.0, 64.0, 0, 0, 0.0f,  0.0f,  -1.0f, // 10
		0.0,  40.0, 64.0, 1, 0, 0.0f,  0.0f,  -1.0f, // 11

		 // left
		 0.0, 0.0, 64.0, 0, 0, -1.0f,  0.0f,  0.0f, // 12
		 0.0, 0.0,  0.0, 1, 0, -1.0f,  0.0f,  0.0f, // 13
		 0.0,  40.0,  0.0, 1, 1, -1.0f,  0.0f,  0.0f, // 14
		 0.0,  40.0, 64.0, 0, 1, -1.0f,  0.0f,  0.0f, // 15

		// upper
		0.0, 40.0,  0.0, 0, 0,   0.0f,  1.0f,  0.0f, // 16
		128.0, 40.0, 0.0, 1, 0,   0.0f,  1.0f,  0.0f, // 17
		128.0, 40.0, 64.0, 1, 1,  0.0f,  1.0f,  0.0f, // 18
		0.0, 40.0, 64.0, 0, 1,   0.0f,  1.0f,  0.0f, // 19

		// bottom
		0.0, 0.0, 0.0, 0, 0, 0.0f,  -1.0f,  0.0f, // 20
		128.0, 0.0, 0.0, 1, 0,  0.0f,  -1.0f,  0.0f, // 21
		128.0, 0.0,  64.0, 1, 1,  0.0f,  -1.0f,  0.0f, // 22
		0.0, 0.0,  64.0, 0, 1, 0.0f,  -1.0f,  0.0f, // 23
	};

	unsigned int indices[] = {
		//0,  1,  2,  0,  2,  3,   // front
		//4,  5,  6,  4,  6,  7,   // right
		8,  9,  10, 8,  10, 11,  // back
		//12, 14, 13, 12, 15, 14,  // left
		//16, 18, 17, 16, 19, 18,  // upper
		//20, 22, 21, 20, 23, 22   // bottom
	};

	cube6b.SetShader(shadowmapShader);
	cube6b.BuildObject(vertices, sizeof(vertices), indices, sizeof(indices));

	cube6b.ApplyTexture("tembok_d.png");
	cube6b.VerticesDraw(sizeof(indices));
	cube6b.transform.SetPosition(glm::vec3(-56.0f, 0.0f, -32.0f));
	cube6b.transform.Scale(glm::vec3(1.0f, 1.0f, 1.0f));
}

void Demo::BuildCube6bout() //ruangannya jadi d
{
	// set up vertex data (and buffer(s)) and configure vertex attributes
	// ------------------------------------------------------------------
	float vertices[] = {
		// format position, tex coords, normal
		// front
		0.0, 0.0, 0.0, 0, 0, 0.0f,  0.0f,  1.0f, // 0
		128.0, 0.0, 0.0, 1, 0,  0.0f,  0.0f,  1.0f, // 1
		128.0,  40.0, 0.0, 1, 1,  0.0f,  0.0f,  1.0f, // 2
		0.0,  40.0, 0.0, 0, 1, 0.0f,  0.0f,  1.0f, // 3

		 // right
		 128.0,  0.0,  0.0, 0, 0, 1.0f,  0.0f,  0.0f, // 4
		 128.0,  0.0, 64.0, 1, 0, 1.0f,  0.0f,  0.0f, // 5
		 128.0, 40.0, 64.0, 1, 1, 1.0f,  0.0f,  0.0f, // 6
		 128.0, 40.0,  0.0, 0, 1, 1.0f,  0.0f,  0.0f, // 7

		// back
		0.0, 0.0, 64.0, 1, 1, 0.0f,  0.0f,  -1.0f, // 8 
		128.0,  0.0, 64.0, 0, 1, 0.0f,  0.0f,  -1.0f, // 9
		128.0,   40.0, 64.0, 0, 0, 0.0f,  0.0f,  -1.0f, // 10
		0.0,  40.0, 64.0, 1, 0, 0.0f,  0.0f,  -1.0f, // 11

		 // left
		 0.0, 0.0, 64.0, 0, 0, -1.0f,  0.0f,  0.0f, // 12
		 0.0, 0.0,  0.0, 1, 0, -1.0f,  0.0f,  0.0f, // 13
		 0.0,  40.0,  0.0, 1, 1, -1.0f,  0.0f,  0.0f, // 14
		 0.0,  40.0, 64.0, 0, 1, -1.0f,  0.0f,  0.0f, // 15

		// upper
		0.0, 40.0,  0.0, 0, 0,   0.0f,  1.0f,  0.0f, // 16
		128.0, 40.0, 0.0, 1, 0,   0.0f,  1.0f,  0.0f, // 17
		128.0, 40.0, 64.0, 1, 1,  0.0f,  1.0f,  0.0f, // 18
		0.0, 40.0, 64.0, 0, 1,   0.0f,  1.0f,  0.0f, // 19

		// bottom
		0.0, 0.0, 0.0, 0, 0, 0.0f,  -1.0f,  0.0f, // 20
		128.0, 0.0, 0.0, 1, 0,  0.0f,  -1.0f,  0.0f, // 21
		128.0, 0.0,  64.0, 1, 1,  0.0f,  -1.0f,  0.0f, // 22
		0.0, 0.0,  64.0, 0, 1, 0.0f,  -1.0f,  0.0f, // 23
	};

	unsigned int indices[] = {
		//0,  1,  2,  0,  2,  3,   // front
		//4,  5,  6,  4,  6,  7,   // right
		8,  9,  10, 8,  10, 11,  // back
		//12, 14, 13, 12, 15, 14,  // left
		//16, 18, 17, 16, 19, 18,  // upper
		//20, 22, 21, 20, 23, 22   // bottom
	};

	cube6bout.SetShader(shadowmapShader);
	cube6bout.BuildObject(vertices, sizeof(vertices), indices, sizeof(indices));

	cube6bout.ApplyTexture("tembok_dx.png");
	cube6bout.VerticesDraw(sizeof(indices));
	cube6bout.transform.SetPosition(glm::vec3(-56.0f, 0.0f, -31.9f));
	cube6bout.transform.Scale(glm::vec3(1.0f, 1.0f, 1.0f));
}

void Demo::BuildCube6kr() //ruangannya
{
	// set up vertex data (and buffer(s)) and configure vertex attributes
	// ------------------------------------------------------------------
	float vertices[] = {
		// format position, tex coords, normal
		// front
		0.0, 0.0, 0.0, 0, 0, 0.0f,  0.0f,  1.0f, // 0
		128.0, 0.0, 0.0, 1, 0,  0.0f,  0.0f,  1.0f, // 1
		128.0,  40.0, 0.0, 1, 1,  0.0f,  0.0f,  1.0f, // 2
		0.0,  40.0, 0.0, 0, 1, 0.0f,  0.0f,  1.0f, // 3

		 // right
		 128.0,  0.0,  0.0, 0, 0, 1.0f,  0.0f,  0.0f, // 4
		 128.0,  0.0, 64.0, 1, 0, 1.0f,  0.0f,  0.0f, // 5
		 128.0, 40.0, 64.0, 1, 1, 1.0f,  0.0f,  0.0f, // 6
		 128.0, 40.0,  0.0, 0, 1, 1.0f,  0.0f,  0.0f, // 7

		// back
		0.0, 0.0, 64.0, 0, 0, 0.0f,  0.0f,  -1.0f, // 8 
		128.0,  0.0, 64.0, 1, 0, 0.0f,  0.0f,  -1.0f, // 9
		128.0,   40.0, 64.0, 1, 1, 0.0f,  0.0f,  -1.0f, // 10
		0.0,  40.0, 64.0, 0, 1, 0.0f,  0.0f,  -1.0f, // 11

		 // left
		 0.0, 0.0, 64.0, 0, 0, 1.0f,  0.0f,  0.0f, // 12
		 0.0, 0.0,  0.0, 1, 0, 1.0f,  0.0f,  0.0f, // 13
		 0.0,  40.0,  0.0, 1, 1, 1.0f,  0.0f,  0.0f, // 14
		 0.0,  40.0, 64.0, 0, 1, 1.0f,  0.0f,  0.0f, // 15

		// upper
		0.0, 40.0,  0.0, 0, 0,   0.0f,  1.0f,  0.0f, // 16
		128.0, 40.0, 0.0, 1, 0,   0.0f,  1.0f,  0.0f, // 17
		128.0, 40.0, 64.0, 1, 1,  0.0f,  1.0f,  0.0f, // 18
		0.0, 40.0, 64.0, 0, 1,   0.0f,  1.0f,  0.0f, // 19

		// bottom
		0.0, 0.0, 0.0, 0, 0, 0.0f,  -1.0f,  0.0f, // 20
		128.0, 0.0, 0.0, 1, 0,  0.0f,  -1.0f,  0.0f, // 21
		128.0, 0.0,  64.0, 1, 1,  0.0f,  -1.0f,  0.0f, // 22
		0.0, 0.0,  64.0, 0, 1, 0.0f,  -1.0f,  0.0f, // 23
	};

	unsigned int indices[] = {
		//0,  1,  2,  0,  2,  3,   // front
		//4,  5,  6,  4,  6,  7,   // right
		//8,  9,  10, 8,  10, 11,  // back
		12, 14, 13, 12, 15, 14,  // left
		//16, 18, 17, 16, 19, 18,  // upper
		//20, 22, 21, 20, 23, 22   // bottom
	};

	cube6kr.SetShader(shadowmapShader);
	cube6kr.BuildObject(vertices, sizeof(vertices), indices, sizeof(indices));

	cube6kr.ApplyTexture("tembok_kn.png");
	cube6kr.VerticesDraw(sizeof(indices));
	cube6kr.transform.SetPosition(glm::vec3(-56.0f, 0.0f, -32.0f));
	cube6kr.transform.Scale(glm::vec3(1.0f, 1.0f, 1.0f));
}

void Demo::BuildCube6kn() //ruangannya
{
	// set up vertex data (and buffer(s)) and configure vertex attributes
	// ------------------------------------------------------------------
	float vertices[] = {
		// format position, tex coords, normal
		// front
		0.0, 0.0, 0.0, 0, 0, 0.0f,  0.0f,  1.0f, // 0
		128.0, 0.0, 0.0, 1, 0,  0.0f,  0.0f,  1.0f, // 1
		128.0,  40.0, 0.0, 1, 1,  0.0f,  0.0f,  1.0f, // 2
		0.0,  40.0, 0.0, 0, 1, 0.0f,  0.0f,  1.0f, // 3

		 // right
		 128.0,  0.0,  0.0, 0, 0, -1.0f,  0.0f,  0.0f, // 4
		 128.0,  0.0, 64.0, 1, 0, -1.0f,  0.0f,  0.0f, // 5
		 128.0, 40.0, 64.0, 1, 1, -1.0f,  0.0f,  0.0f, // 6
		 128.0, 40.0,  0.0, 0, 1, -1.0f,  0.0f,  0.0f, // 7

		// back
		0.0, 0.0, 64.0, 0, 0, 0.0f,  0.0f,  -1.0f, // 8 
		128.0,  0.0, 64.0, 1, 0, 0.0f,  0.0f,  -1.0f, // 9
		128.0,   40.0, 64.0, 1, 1, 0.0f,  0.0f,  -1.0f, // 10
		0.0,  40.0, 64.0, 0, 1, 0.0f,  0.0f,  -1.0f, // 11

		 // left
		 0.0, 0.0, 64.0, 0, 0, -1.0f,  0.0f,  0.0f, // 12
		 0.0, 0.0,  0.0, 1, 0, -1.0f,  0.0f,  0.0f, // 13
		 0.0,  40.0,  0.0, 1, 1, -1.0f,  0.0f,  0.0f, // 14
		 0.0,  40.0, 64.0, 0, 1, -1.0f,  0.0f,  0.0f, // 15

		// upper
		0.0, 40.0,  0.0, 0, 0,   0.0f,  1.0f,  0.0f, // 16
		128.0, 40.0, 0.0, 1, 0,   0.0f,  1.0f,  0.0f, // 17
		128.0, 40.0, 64.0, 1, 1,  0.0f,  1.0f,  0.0f, // 18
		0.0, 40.0, 64.0, 0, 1,   0.0f,  1.0f,  0.0f, // 19

		// bottom
		0.0, 0.0, 0.0, 0, 0, 0.0f,  -1.0f,  0.0f, // 20
		128.0, 0.0, 0.0, 1, 0,  0.0f,  -1.0f,  0.0f, // 21
		128.0, 0.0,  64.0, 1, 1,  0.0f,  -1.0f,  0.0f, // 22
		0.0, 0.0,  64.0, 0, 1, 0.0f,  -1.0f,  0.0f, // 23
	};

	unsigned int indices[] = {
		//0,  1,  2,  0,  2,  3,   // front
		4,  5,  6,  4,  6,  7,   // right
		//8,  9,  10, 8,  10, 11,  // back
		//12, 14, 13, 12, 15, 14,  // left
		//16, 18, 17, 16, 19, 18,  // upper
		//20, 22, 21, 20, 23, 22   // bottom
	};

	cube6kn.SetShader(shadowmapShader);
	cube6kn.BuildObject(vertices, sizeof(vertices), indices, sizeof(indices));

	cube6kn.ApplyTexture("tembok_kn.png");
	cube6kn.VerticesDraw(sizeof(indices));
	cube6kn.transform.SetPosition(glm::vec3(-56.0f, 0.0f, -32.0f));
	cube6kn.transform.Scale(glm::vec3(1.0f, 1.0f, 1.0f));
}

void Demo::BuildCube6a() //ruangannya
{
	// set up vertex data (and buffer(s)) and configure vertex attributes
	// ------------------------------------------------------------------
	float vertices[] = {
		// format position, tex coords, normal
		// front
		0.0, 0.0, 0.0, 0, 0, 0.0f,  0.0f,  1.0f, // 0
		128.0, 0.0, 0.0, 1, 0,  0.0f,  0.0f,  1.0f, // 1
		128.0,  40.0, 0.0, 1, 1,  0.0f,  0.0f,  1.0f, // 2
		0.0,  40.0, 0.0, 0, 1, 0.0f,  0.0f,  1.0f, // 3

		 // right
		 128.0,  0.0,  0.0, 0, 0, 1.0f,  0.0f,  0.0f, // 4
		 128.0,  0.0, 64.0, 1, 0, 1.0f,  0.0f,  0.0f, // 5
		 128.0, 40.0, 64.0, 1, 1, 1.0f,  0.0f,  0.0f, // 6
		 128.0, 40.0,  0.0, 0, 1, 1.0f,  0.0f,  0.0f, // 7

		// back
		0.0, 0.0, 64.0, 0, 0, 0.0f,  0.0f,  -1.0f, // 8 
		128.0,  0.0, 64.0, 1, 0, 0.0f,  0.0f,  -1.0f, // 9
		128.0,   40.0, 64.0, 1, 1, 0.0f,  0.0f,  -1.0f, // 10
		0.0,  40.0, 64.0, 0, 1, 0.0f,  0.0f,  -1.0f, // 11

		 // left
		 0.0, 0.0, 64.0, 0, 0, -1.0f,  0.0f,  0.0f, // 12
		 0.0, 0.0,  0.0, 1, 0, -1.0f,  0.0f,  0.0f, // 13
		 0.0,  40.0,  0.0, 1, 1, -1.0f,  0.0f,  0.0f, // 14
		 0.0,  40.0, 64.0, 0, 1, -1.0f,  0.0f,  0.0f, // 15

		// upper
		0.0, 40.0,  0.0, 0, 0,   0.0f,  1.0f,  0.0f, // 16
		128.0, 40.0, 0.0, 1, 0,   0.0f,  1.0f,  0.0f, // 17
		128.0, 40.0, 64.0, 1, 1,  0.0f,  1.0f,  0.0f, // 18
		0.0, 40.0, 64.0, 0, 1,   0.0f,  1.0f,  0.0f, // 19

		// bottom
		0.0, 0.0, 0.0, 0, 0, 0.0f,  -1.0f,  0.0f, // 20
		128.0, 0.0, 0.0, 1, 0,  0.0f,  -1.0f,  0.0f, // 21
		128.0, 0.0,  64.0, 1, 1,  0.0f,  -1.0f,  0.0f, // 22
		0.0, 0.0,  64.0, 0, 1, 0.0f,  -1.0f,  0.0f, // 23
	};

	unsigned int indices[] = {
		//0,  1,  2,  0,  2,  3,   // front
		//4,  5,  6,  4,  6,  7,   // right
		//8,  9,  10, 8,  10, 11,  // back
		//12, 14, 13, 12, 15, 14,  // left
		16, 18, 17, 16, 19, 18,  // upper
		//20, 22, 21, 20, 23, 22   // bottom
	};

	cube6a.SetShader(shadowmapShader);
	cube6a.BuildObject(vertices, sizeof(vertices), indices, sizeof(indices));

	cube6a.ApplyTexture("tembok_a.png");
	cube6a.VerticesDraw(sizeof(indices));
	cube6a.transform.SetPosition(glm::vec3(-56.0f, 0.0f, -32.0f));
	cube6a.transform.Scale(glm::vec3(1.0f, 1.0f, 1.0f));
}

void Demo::BuildCube7() //ac 1 kecuali depan
{
	// set up vertex data (and buffer(s)) and configure vertex attributes
	// ------------------------------------------------------------------
	float vertices[] = {
		// format position, tex coords, normal
		// front
		0.0, 0.0, 0.0, 0, 0, 0.0f,  0.0f,  1.0f, // 0
		24.0, 0.0, 0.0, 1, 0,  0.0f,  0.0f,  1.0f, // 1
		24.0,  8.0, 0.0, 1, 1,  0.0f,  0.0f,  1.0f, // 2
		0.0,  8.0, 0.0, 0, 1, 0.0f,  0.0f,  1.0f, // 3

		 // right
		 24.0,  0.0,  0.0, 0, 0, 1.0f,  0.0f,  0.0f, // 4
		 24.0,  0.0, 8.0, 1, 0, 1.0f,  0.0f,  0.0f, // 5
		 24.0, 8.0, 8.0, 1, 1, 1.0f,  0.0f,  0.0f, // 6
		 24.0, 8.0,  0.0, 0, 1, 1.0f,  0.0f,  0.0f, // 7

		// back
		0.0, 0.0, 8.0, 0, 0, 0.0f,  0.0f,  -1.0f, // 8 
		24.0,  0.0, 8.0, 1, 0, 0.0f,  0.0f,  -1.0f, // 9
		24.0,   8.0, 8.0, 1, 1, 0.0f,  0.0f,  -1.0f, // 10
		0.0,  8.0, 8.0, 0, 1, 0.0f,  0.0f,  -1.0f, // 11

		 // left
		 0.0, 0.0, 8.0, 0, 0, -1.0f,  0.0f,  0.0f, // 12
		 0.0, 0.0,  0.0, 1, 0, -1.0f,  0.0f,  0.0f, // 13
		 0.0,  8.0,  0.0, 1, 1, -1.0f,  0.0f,  0.0f, // 14
		 0.0,  8.0, 8.0, 0, 1, -1.0f,  0.0f,  0.0f, // 15

		// upper
		0.0, 8.0,  0.0, 0, 0,   0.0f,  1.0f,  0.0f, // 16
		24.0, 8.0, 0.0, 1, 0,   0.0f,  1.0f,  0.0f, // 17
		24.0, 8.0, 8.0, 1, 1,  0.0f,  1.0f,  0.0f, // 18
		0.0, 8.0, 8.0, 0, 1,   0.0f,  1.0f,  0.0f, // 19

		// bottom
		0.0, 0.0, 0.0, 0, 0, 0.0f,  -1.0f,  0.0f, // 20
		24.0, 0.0, 0.0, 1, 0,  0.0f,  -1.0f,  0.0f, // 21
		24.0, 0.0,  8.0, 1, 1,  0.0f,  -1.0f,  0.0f, // 22
		0.0, 0.0,  8.0, 0, 1, 0.0f,  -1.0f,  0.0f, // 23
	};

	unsigned int indices[] = {
		0,  1,  2,  0,  2,  3,   // front
		4,  5,  6,  4,  6,  7,   // right
		//8,  9,  10, 8,  10, 11,  // back
		12, 14, 13, 12, 15, 14,  // left
		16, 18, 17, 16, 19, 18,  // upper
		20, 22, 21, 20, 23, 22   // bottom
	};

	cube7.SetShader(shadowmapShader);
	cube7.BuildObject(vertices, sizeof(vertices), indices, sizeof(indices));

	cube7.ApplyTexture("lainnya ac.png");
	cube7.VerticesDraw(sizeof(indices));
	cube7.transform.SetPosition(glm::vec3(0.0f, 32.0f, -32.0f));
	cube7.transform.Scale(glm::vec3(1.0f, 1.0f, 1.0f));
}

void Demo::BuildCube7d() //ac 1 depan
{
	// set up vertex data (and buffer(s)) and configure vertex attributes
	// ------------------------------------------------------------------
	float vertices[] = {
		// format position, tex coords, normal
		// front
		0.0, 0.0, 0.0, 0, 0, 0.0f,  0.0f,  1.0f, // 0
		24.0, 0.0, 0.0, 1, 0,  0.0f,  0.0f,  1.0f, // 1
		24.0,  8.0, 0.0, 1, 1,  0.0f,  0.0f,  1.0f, // 2
		0.0,  8.0, 0.0, 0, 1, 0.0f,  0.0f,  1.0f, // 3

		 // right
		 24.0,  0.0,  0.0, 0, 0, 1.0f,  0.0f,  0.0f, // 4
		 24.0,  0.0, 8.0, 1, 0, 1.0f,  0.0f,  0.0f, // 5
		 24.0, 8.0, 8.0, 1, 1, 1.0f,  0.0f,  0.0f, // 6
		 24.0, 8.0,  0.0, 0, 1, 1.0f,  0.0f,  0.0f, // 7

		// back
		0.0, 0.0, 8.0, 0, 0, 0.0f,  0.0f,  1.0f, // 8 
		24.0,  0.0, 8.0, 1, 0, 0.0f,  0.0f,  1.0f, // 9
		24.0,   8.0, 8.0, 1, 1, 0.0f,  0.0f,  1.0f, // 10
		0.0,  8.0, 8.0, 0, 1, 0.0f,  0.0f,  1.0f, // 11

		 // left
		 0.0, 0.0, 8.0, 0, 0, -1.0f,  0.0f,  0.0f, // 12
		 0.0, 0.0,  0.0, 1, 0, -1.0f,  0.0f,  0.0f, // 13
		 0.0,  8.0,  0.0, 1, 1, -1.0f,  0.0f,  0.0f, // 14
		 0.0,  8.0, 8.0, 0, 1, -1.0f,  0.0f,  0.0f, // 15

		// upper
		0.0, 8.0,  0.0, 0, 0,   0.0f,  1.0f,  0.0f, // 16
		24.0, 8.0, 0.0, 1, 0,   0.0f,  1.0f,  0.0f, // 17
		24.0, 8.0, 8.0, 1, 1,  0.0f,  1.0f,  0.0f, // 18
		0.0, 8.0, 8.0, 0, 1,   0.0f,  1.0f,  0.0f, // 19

		// bottom
		0.0, 0.0, 0.0, 0, 0, 0.0f,  -1.0f,  0.0f, // 20
		24.0, 0.0, 0.0, 1, 0,  0.0f,  -1.0f,  0.0f, // 21
		24.0, 0.0,  8.0, 1, 1,  0.0f,  -1.0f,  0.0f, // 22
		0.0, 0.0,  8.0, 0, 1, 0.0f,  -1.0f,  0.0f, // 23
	};

	unsigned int indices[] = {
		//0,  1,  2,  0,  2,  3,   // front
		//4,  5,  6,  4,  6,  7,   // right
		8,  9,  10, 8,  10, 11,  // back
		//12, 14, 13, 12, 15, 14,  // left
		//16, 18, 17, 16, 19, 18,  // upper
		//20, 22, 21, 20, 23, 22   // bottom
	};

	cube7d.SetShader(shadowmapShader);
	cube7d.BuildObject(vertices, sizeof(vertices), indices, sizeof(indices));

	cube7d.ApplyTexture("ac depan.png");
	cube7d.VerticesDraw(sizeof(indices));
	cube7d.transform.SetPosition(glm::vec3(0.0f, 32.0f, -32.0f));
	cube7d.transform.Scale(glm::vec3(1.0f, 1.0f, 1.0f));
}

void Demo::BuildCube9() //ruangannya
{
	// set up vertex data (and buffer(s)) and configure vertex attributes
	// ------------------------------------------------------------------
	float vertices[] = {
		// format position, tex coords, normal
		// front
		0.0, 0.0, 0.0, 0, 0, 0.0f,  0.0f,  1.0f, // 0
		2.0, 0.0, 0.0, 1, 0,  0.0f,  0.0f,  1.0f, // 1
		2.0,  16.0, 0.0, 1, 1,  0.0f,  0.0f,  1.0f, // 2
		0.0,  16.0, 0.0, 0, 1, 0.0f,  0.0f,  1.0f, // 3

		 // right
		 2.0,  0.0,  0.0, 1, 1, 1.0f,  0.0f,  0.0f, // 4
		 2.0,  0.0, 32.0, 0, 1, 1.0f,  0.0f,  0.0f, // 5
		 2.0, 16.0, 32.0, 0, 0, 1.0f,  0.0f,  0.0f, // 6
		 2.0, 16.0,  0.0, 1, 0, 1.0f,  0.0f,  0.0f, // 7

		// back
		0.0, 0.0, 32.0, 0, 0, 0.0f,  0.0f,  -1.0f, // 8 
		2.0,  0.0, 32.0, 1, 0, 0.0f,  0.0f,  -1.0f, // 9
		2.0,   16.0, 32.0, 1, 1, 0.0f,  0.0f,  -1.0f, // 10
		0.0,  16.0, 32.0, 0, 1, 0.0f,  0.0f,  -1.0f, // 11

		 // left
		 0.0, 0.0, 32.0, 0, 0, -1.0f,  0.0f,  0.0f, // 12
		 0.0, 0.0,  0.0, 1, 0, -1.0f,  0.0f,  0.0f, // 13
		 0.0,  16.0,  0.0, 1, 1, -1.0f,  0.0f,  0.0f, // 14
		 0.0,  16.0, 32.0, 0, 1, -1.0f,  0.0f,  0.0f, // 15

		// upper
		0.0, 16.0,  0.0, 0, 0,   0.0f,  1.0f,  0.0f, // 16
		2.0, 16.0, 0.0, 1, 0,   0.0f,  1.0f,  0.0f, // 17
		2.0, 16.0, 32.0, 1, 1,  0.0f,  1.0f,  0.0f, // 18
		0.0, 16.0, 32.0, 0, 1,   0.0f,  1.0f,  0.0f, // 19

		// bottom
		0.0, 0.0, 0.0, 0, 0, 0.0f,  -1.0f,  0.0f, // 20
		2.0, 0.0, 0.0, 1, 0,  0.0f,  -1.0f,  0.0f, // 21
		2.0, 0.0,  32.0, 1, 1,  0.0f,  -1.0f,  0.0f, // 22
		0.0, 0.0,  32.0, 0, 1, 0.0f,  -1.0f,  0.0f, // 23
	};

	unsigned int indices[] = {
		/*0,  1,  2,  0,  2,  3, */  // front
		4,  5,  6,  4,  6,  7   // right
		//8,  9,  10, 8,  10, 11,  // back
		//12, 14, 13, 12, 15, 14,  // left
		//16, 18, 17, 16, 19, 18,  // upper
		//20, 22, 21, 20, 23, 22   // bottom
	};

	cube9.SetShader(shadowmapShader);
	cube9.BuildObject(vertices, sizeof(vertices), indices, sizeof(indices));

	cube9.ApplyTexture("rakrokok.png");
	cube9.VerticesDraw(sizeof(indices));
	cube9.transform.SetPosition(glm::vec3(-56.0f, 0.0f, 0.0f));
	cube9.transform.Scale(glm::vec3(1.0f, 1.0f, 1.0f));
}

void Demo::BuildCube9side() //ruangannya
{
	// set up vertex data (and buffer(s)) and configure vertex attributes
	// ------------------------------------------------------------------
	float vertices[] = {
		// format position, tex coords, normal
		// front
		0.0, 0.0, 0.0, 0, 0, 0.0f,  0.0f,  1.0f, // 0
		2.0, 0.0, 0.0, 1, 0,  0.0f,  0.0f,  1.0f, // 1
		2.0,  16.0, 0.0, 1, 1,  0.0f,  0.0f,  1.0f, // 2
		0.0,  16.0, 0.0, 0, 1, 0.0f,  0.0f,  1.0f, // 3

		 // right
		 2.0,  0.0,  0.0, 0, 0, 1.0f,  0.0f,  0.0f, // 4
		 2.0,  0.0, 32.0, 1, 0, 1.0f,  0.0f,  0.0f, // 5
		 2.0, 16.0, 32.0, 1, 1, 1.0f,  0.0f,  0.0f, // 6
		 2.0, 16.0,  0.0, 0, 1, 1.0f,  0.0f,  0.0f, // 7

		// back
		0.0, 0.0, 32.0, 0, 0, 0.0f,  0.0f,  -1.0f, // 8 
		2.0,  0.0, 32.0, 1, 0, 0.0f,  0.0f,  -1.0f, // 9
		2.0,   16.0, 32.0, 1, 1, 0.0f,  0.0f,  -1.0f, // 10
		0.0,  16.0, 32.0, 0, 1, 0.0f,  0.0f,  -1.0f, // 11

		 // left
		 0.0, 0.0, 32.0, 0, 0, -1.0f,  0.0f,  0.0f, // 12
		 0.0, 0.0,  0.0, 1, 0, -1.0f,  0.0f,  0.0f, // 13
		 0.0,  16.0,  0.0, 1, 1, -1.0f,  0.0f,  0.0f, // 14
		 0.0,  16.0, 32.0, 0, 1, -1.0f,  0.0f,  0.0f, // 15

		// upper
		0.0, 16.0,  0.0, 0, 0,   0.0f,  1.0f,  0.0f, // 16
		2.0, 16.0, 0.0, 1, 0,   0.0f,  1.0f,  0.0f, // 17
		2.0, 16.0, 32.0, 1, 1,  0.0f,  1.0f,  0.0f, // 18
		0.0, 16.0, 32.0, 0, 1,   0.0f,  1.0f,  0.0f, // 19

		// bottom
		0.0, 0.0, 0.0, 0, 0, 0.0f,  -1.0f,  0.0f, // 20
		2.0, 0.0, 0.0, 1, 0,  0.0f,  -1.0f,  0.0f, // 21
		2.0, 0.0,  32.0, 1, 1,  0.0f,  -1.0f,  0.0f, // 22
		0.0, 0.0,  32.0, 0, 1, 0.0f,  -1.0f,  0.0f, // 23
	};

	unsigned int indices[] = {
		0,  1,  2,  0,  2,  3,   // front
		/*4,  5,  6,  4,  6,  7, */  // right
		8,  9,  10, 8,  10, 11,  // back
		/*12, 14, 13, 12, 15, 14,*/  // left
		16, 18, 17, 16, 19, 18,  // upper
		20, 22, 21, 20, 23, 22   // bottom
	};

	cube9side.SetShader(shadowmapShader);
	cube9side.BuildObject(vertices, sizeof(vertices), indices, sizeof(indices));

	cube9side.ApplyTexture("Kulkasside.png");
	cube9side.VerticesDraw(sizeof(indices));
	cube9side.transform.SetPosition(glm::vec3(-56.0f, 0.0f, 0.0f));
	cube9side.transform.Scale(glm::vec3(1.0f, 1.0f, 1.0f));
}

//void Demo::BuildCube10() //ruangannya jadi b
//{
//	// set up vertex data (and buffer(s)) and configure vertex attributes
//	// ------------------------------------------------------------------
//	float vertices[] = {
//		// format position, tex coords, normal
//		// front
//		0.0, 0.0, 0.0, 1, 1, 0.0f,  0.0f,  1.0f, // 0
//		64.0, 0.0, 0.0, 0, 1,  0.0f,  0.0f,  1.0f, // 1
//		64.0,  16.0, 0.0, 0, 0,  0.0f,  0.0f,  1.0f, // 2
//		0.0,  16.0, 0.0, 1, 0, 0.0f,  0.0f,  1.0f, // 3
//
//		 // right
//		 64.0,  0.0,  0.0, 0, 0, 1.0f,  0.0f,  0.0f, // 4
//		 64.0,  0.0, 64.0, 1, 0, 1.0f,  0.0f,  0.0f, // 5
//		 64.0, 16.0, 64.0, 1, 1, 1.0f,  0.0f,  0.0f, // 6
//		 64.0, 16.0,  0.0, 0, 1, 1.0f,  0.0f,  0.0f, // 7
//
//		// back
//		0.0, 0.0, 64.0, 0, 0, 0.0f,  0.0f,  -1.0f, // 8 
//		64.0,  0.0, 64.0, 1, 0, 0.0f,  0.0f,  -1.0f, // 9
//		64.0,   16.0, 64.0, 1, 1, 0.0f,  0.0f,  -1.0f, // 10
//		0.0,  16.0, 64.0, 0, 1, 0.0f,  0.0f,  -1.0f, // 11
//
//		 // left
//		 0.0, 0.0, 64.0, 0, 0, -1.0f,  0.0f,  0.0f, // 12
//		 0.0, 0.0,  0.0, 1, 0, -1.0f,  0.0f,  0.0f, // 13
//		 0.0,  16.0,  0.0, 1, 1, -1.0f,  0.0f,  0.0f, // 14
//		 0.0,  16.0, 64.0, 0, 1, -1.0f,  0.0f,  0.0f, // 15
//
//		// upper
//		0.0, 16.0,  0.0, 0, 0,   0.0f,  1.0f,  0.0f, // 16
//		64.0, 16.0, 0.0, 1, 0,   0.0f,  1.0f,  0.0f, // 17
//		64.0, 16.0, 64.0, 1, 1,  0.0f,  1.0f,  0.0f, // 18
//		0.0, 16.0, 64.0, 0, 1,   0.0f,  1.0f,  0.0f, // 19
//
//		// bottom
//		0.0, 0.0, 0.0, 0, 0, 0.0f,  -1.0f,  0.0f, // 20
//		64.0, 0.0, 0.0, 1, 0,  0.0f,  -1.0f,  0.0f, // 21
//		64.0, 0.0,  64.0, 1, 1,  0.0f,  -1.0f,  0.0f, // 22
//		0.0, 0.0,  64.0, 0, 1, 0.0f,  -1.0f,  0.0f, // 23
//	};
//
//	unsigned int indices[] = {
//		0,  1,  2,  0,  2,  3,   // front
//		//4,  5,  6,  4,  6,  7,   // right
//		//8,  9,  10, 8,  10, 11,  // back
//		//12, 14, 13, 12, 15, 14,  // left
//		//16, 18, 17, 16, 19, 18,  // upper
//		//20, 22, 21, 20, 23, 22   // bottom
//	};
//
//	cube6d.SetShader(shadowmapShader);
//	cube6d.BuildObject(vertices, sizeof(vertices), indices, sizeof(indices));
//
//	cube6d.ApplyTexture("tembok_b.png");
//	cube6d.VerticesDraw(sizeof(indices));
//	cube6d.transform.SetOrigin(glm::vec3(0.0f, 0.0f, 0.0f));
//	cube6d.transform.SetPosition(glm::vec3(-56.0f, 0.0f, -32.0f));
//	cube6d.transform.Scale(glm::vec3(1.0f, 1.0f, 1.0f));
//}

void Demo::BuildDepthMap() {
	// configure depth map FBO
	// -----------------------
	glGenFramebuffers(1, &depthMapFBO);
	// create depth texture
	const unsigned int SHADOW_WIDTH = 1024, SHADOW_HEIGHT = 1024;
	glGenTextures(1, &depthMap);
	glBindTexture(GL_TEXTURE_2D, depthMap);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_DEPTH_COMPONENT, this->SHADOW_WIDTH, this->SHADOW_HEIGHT, 0, GL_DEPTH_COMPONENT, GL_FLOAT, NULL);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_BORDER);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_BORDER);
	float borderColor[] = { 1.0, 1.0, 1.0, 1.0 };
	glTexParameterfv(GL_TEXTURE_2D, GL_TEXTURE_BORDER_COLOR, borderColor);

	// attach depth texture as FBO's depth buffer
	glBindFramebuffer(GL_FRAMEBUFFER, depthMapFBO);
	glFramebufferTexture2D(GL_FRAMEBUFFER, GL_DEPTH_ATTACHMENT, GL_TEXTURE_2D, depthMap, 0);
	glDrawBuffer(GL_NONE);
	glReadBuffer(GL_NONE);
	glBindFramebuffer(GL_FRAMEBUFFER, 0);

}

void Demo::BuildShaders()
{
	// build and compile our shader program
	// ------------------------------------
	shadowmapShader = shader.GetBuildShader("shadowMapping.vert", "shadowMapping.frag", nullptr);
	depthmapShader = shader.GetBuildShader("depthMap.vert", "depthMap.frag", nullptr);
}

int main(int argc, char** argv) {
	RenderEngine& app = Demo();
	app.Start("Shadow Mapping Demo", 800, 600, false, false);
}