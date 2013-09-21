#pragma once

#include <opencv2\core\core.hpp>
namespace TCD {
	class Detector {

	public:
		bool isDone();
		virtual ~Detector() {
		};

	protected:
		int m_height;
		int m_width;
		float m_sigmaD;
		float m_sigmaI;

		bool done;
		cv::Mat m_image;

		std::vector<float> m_gaussD;
		std::vector<float> m_gaussI;
	};
};