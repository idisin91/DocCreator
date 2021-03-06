#include "GradientDomainDegradationQ.hpp"
#include "Utils/convertor.h"

namespace dc {

  namespace GradientDomainDegradation {

    QImage
    degradation(const QImage &img,
		const QString &stainImageDir,
		size_t numStainsToInsert,
		InsertType insertType,
		bool doRotations)
    {
      const cv::Mat matIn = Convertor::getCvMat(img);

      const cv::Mat matOut = dc::GradientDomainDegradation::degradation(matIn, stainImageDir.toStdString(), numStainsToInsert, insertType, doRotations);

      const QImage out = Convertor::getQImage(matOut);

      return out;
    }

  } //namespace GradientDomainDegradation

  QImage
  GradientDomainDegradationQ::apply()
  {
    const QImage out =
      GradientDomainDegradation::degradation(_original, _stainImageDir, _numStainsToInsert, _insertType, _doRotations);

    emit imageReady(out);

    return out;
  }
  
} //namespace dc
  
    
