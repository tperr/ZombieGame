#pragma once
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

namespace Bengine
{
	class Camera2D
	{
	public:
		Camera2D();
		~Camera2D();

		void update();

		glm::vec2 convertScreenToWorld(glm::vec2 screenCoords);

		void init(int screenWidth, int screenHeight);

		void setScale(float newScale)
		{
			_scale = newScale;
			_needsMatrixUpdate = true;
		}

		void setPosition(const glm::vec2& newPosition)
		{
			_position = newPosition;
			_needsMatrixUpdate = true;
		}


		float getScale()
		{
			return _scale;
		}

		glm::vec2 getPosition()
		{
			return _position;
		}

		glm::mat4 getCameraMatrix()
		{
			return _cameraMatrix;
		}

	private:
		int _screenWidth, _screenHeight;
		bool _needsMatrixUpdate;
		float _scale;
		// same as glsl vec2, just 2 floats
		glm::vec2 _position;
		// mat4 stands for a 4x4 matrix
		glm::mat4 _cameraMatrix;

		glm::mat4 _orthoMatrix;
	};

}