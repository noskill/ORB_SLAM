#include "ResourceManager.h"
#include <stdexcept>


namespace ORB_SLAM
{

ResourceManager::ResourceManager():
mbVocLoad(false), mFilePath("")
{}

//SingleTon Instance
ResourceManager &ResourceManager::getInstance()
{
   static ResourceManager instance;
   return instance;
}

void ResourceManager::setVocabularyFilePath(std::string & path){
 mFilePath = path;
}


ORB_SLAM::ORBVocabulary & ResourceManager::getORBVocabulary(){
   if (mFilePath == ""){
	   throw logic_error("FilePath not initiealized");
   }
   if (!mbVocLoad){
       mbVocLoad = this->mVocabulary.loadFromTextFile(mFilePath);
       if (!mbVocLoad){
	   cerr << "Wrong path to vocabulary. Path must be absolut or relative to ORB_SLAM package directory." << endl;
	   cerr << "Falied to open at: " << mFilePath << endl;
           throw runtime_error("Can't load vocabulary, check stderr");
       }
   }
   return mVocabulary;
}



}
