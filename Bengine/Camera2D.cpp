#include "Camera2D.h"
#include <iostream>

namespace Bengine
{
	Camera2D::Camera2D() : _screenWidth(500), _screenHeight(500), _needsMatrixUpdate(true), _scale(1), _position(0.0f, 0.0f), _cameraMatrix(1.0f), _orthoMatrix(0.0f)
	{

	}

	Camera2D::~Camera2D()
	{

	}

	void Camera2D::update()
	{
		if (_needsMatrixUpdate)
		{
			glm::vec3 translate(-_position.x + _screenWidth/2, -_position.y + _screenHeight, 0.0f);
			_cameraMatrix = glm::translate(_orthoMatrix, translate);
			//std::cout << "Ortho: " << _orthoMatrix[0][0] << ", " << _orthoMatrix[0][1] << ", " << _orthoMatrix[0][2] << ", " << _orthoMatrix[0][3] << "\n";
			//std::cout << _orthoMatrix[1][0] << ", " << _orthoMatrix[1][1] << ", " << _orthoMatrix[1][2] << ", " << _orthoMatrix[1][3] << "\n";
			//std::cout << _orthoMatrix[2][0] << ", " << _orthoMatrix[2][1] << ", " << _orthoMatrix[2][2] << ", " << _orthoMatrix[2][3] << "\n";
			//std::cout << _orthoMatrix[3][0] << ", " << _orthoMatrix[3][1] << ", " << _orthoMatrix[3][2] << ", " << _orthoMatrix[3][3] << "\n\n\n\n";
			glm::vec3 scale(_scale, _scale, 0.0f);
			_cameraMatrix = glm::scale(glm::mat4(1.0f), scale) * _cameraMatrix;

			_needsMatrixUpdate = false;
		}
	}

	glm::vec2 Camera2D::convertScreenToWorld(glm::vec2 screenCoords)
	{
		// invert y coords
		screenCoords.y = _screenHeight - screenCoords.y;
		// 0 is center
		screenCoords -= glm::vec2(_screenWidth / 2, _screenHeight / 2);
		// scale coordinates
		screenCoords /= _scale;
		// translate w/camera position
		screenCoords += _position;
		return screenCoords;
	}

	void Camera2D::init(int screenWidth, int screenHeight)
	{
		_screenWidth = screenWidth;
		_screenHeight = screenHeight;
		_orthoMatrix = glm::ortho(0.0f, (float)_screenWidth, 0.0f, (float)_screenHeight);
	}

}