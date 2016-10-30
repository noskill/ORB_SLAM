#include <string.h>
#include "ORBVocabulary.h"

#ifndef RESOURCEMANAGER_H
#define RESOURCEMANAGER_H

namespace ORB_SLAM
{

class ResourceManager
{
public :

   // SingleTon Instance
   // Singleton Instance of our resource manager
   static ResourceManager & getInstance();

   void setVocabularyFilePath(std::string & path);

   ORB_SLAM::ORBVocabulary & getORBVocabulary();
private:
    // Constructor
   ResourceManager();
   ORB_SLAM::ORBVocabulary mVocabulary;
   bool mbVocLoad;
   std::string mFilePath;
};

}

#endif // RESOURCEMANAGER_H
