
#include <ORBVocabulary.h>
#include <ResourceManager.h>
#include <boost/serialization/base_object.hpp>
#include <boost/serialization/split_free.hpp>
#include <boost/serialization/vector.hpp>


#ifndef VOCABULARY_SERIALIZATION_H
#define VOCABULARY_SERIALIZATION_H

BOOST_SERIALIZATION_SPLIT_FREE(::ORB_SLAM::ORBVocabulary)
namespace boost {
  namespace serialization {

    /** Serialization support for cv::Mat */
    template<class Archive>
    void save(Archive & ar, const ::ORB_SLAM::ORBVocabulary & orb, const unsigned int version)
    {
    }

    /** Serialization support for cv::Mat */
    template<class Archive>
    void load(Archive & ar, ::ORB_SLAM::ORBVocabulary & orb, const unsigned int version)
    {
      orb = ::ORB_SLAM::ResourceManager::getInstance().getORBVocabulary();
    }

  }
}

#endif // VOCABULARY_SERIALIZATION_H


