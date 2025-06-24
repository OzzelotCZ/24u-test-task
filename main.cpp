#include <iostream>
#include <fstream>
#include <taglib/attachedpictureframe.h>
#include <taglib/id3v2frame.h>
#include <taglib/mpegfile.h>
#include <taglib/tag.h>
#include <taglib/id3v2tag.h>
#include <taglib/id3v2framefactory.h>
#include <string>

int main(int argc, char** argv){
    if(argc != 2){
        std::cout << "Usage: " << argv[0] << " <file.mp3>" << std::endl;
        return -1;
    }
    //open file, hoping it exists
    TagLib::MPEG::File mp3file(argv[1]);
    std::cout << mp3file.tag()->title() << std::endl;
    //get APIC frame from file
    TagLib::ID3v2::FrameList flist =  mp3file.ID3v2Tag()->frameListMap()["APIC"];
    TagLib::ID3v2::FrameList::ConstIterator it = flist.begin();
    TagLib::ID3v2::AttachedPictureFrame* mypic = static_cast<TagLib::ID3v2::AttachedPictureFrame*>(*it);
    //construct file name to output cover image to
    std::string coverfilename = mp3file.tag()->artist().toCString();
    coverfilename.append(" - ");
    coverfilename.append(mp3file.tag()->title().toCString());
    if(mypic->mimeType() == "image/png"){
        coverfilename += ".png";
    }
    else if(mypic->mimeType() == "image/jpeg"){
        coverfilename += ".jpg";
    }
    //open file to output cover image to
    std::fstream cover;
    cover.open(coverfilename,std::ios::out);
    cover << mypic->picture();
    cover.close();
    std::cout << "Cover image output to " << coverfilename << std::endl;
    return 0;
}