
#include <opencv2/opencv.hpp>
#include <boost/serialization/split_free.hpp>
#include <boost/serialization/vector.hpp>

BOOST_SERIALIZATION_SPLIT_FREE(::cv::KeyPoint)
namespace boost {
  namespace serialization {

    /** Serialization support for cv::Mat */
    template<class Archive>
    void save(Archive & ar, const ::cv::KeyPoint& p, const unsigned int version)
    {
	    ar & p.angle;
	    ar & p.class_id;
	    ar & p.octave;
	    ar & p.pt.x;
	    ar & p.pt.y;
	    ar & p.response;
	    ar & p.size;
    }

    /** Serialization support for cv::Mat */
    template<class Archive>
    void load(Archive & ar, ::cv::KeyPoint & p, const unsigned int version)
    {
      ar & p.angle;
      ar & p.class_id;
      ar & p.octave;
      float x,y;
      ar & x;
      ar & y;
      cv::Point2f pt{x, y};
      p.pt = pt;
      ar & p.response;
      ar & p.size;
    }

  }
}


