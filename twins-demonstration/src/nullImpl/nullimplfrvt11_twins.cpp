/*
 * This software was developed at the National Institute of Standards and
 * Technology (NIST) by employees of the Federal Government in the course
 * of their official duties. Pursuant to title 17 Section 105 of the
 * United States Code, this software is not subject to copyright protection
 * and is in the public domain. NIST assumes no responsibility  whatsoever for
 * its use by other parties, and makes no guarantees, expressed or implied,
 * about its quality, reliability, or any other characteristic.
 */

#include <algorithm>
#include <cstring>
#include <cstdlib>

#include "nullimplfrvt11_twins.h"

using namespace std;
using namespace FRVT;
using namespace FRVT_11;

NullImplFRVT11_TWINS::NullImplFRVT11_TWINS() {}

NullImplFRVT11_TWINS::~NullImplFRVT11_TWINS() {}

ReturnStatus
NullImplFRVT11_TWINS::initialize(const std::string &configDir)
{
    return ReturnStatus(ReturnCode::Success);
}

ReturnStatus
NullImplFRVT11_TWINS::createTemplate(
        const std::vector<Image> &faces,
        TemplateRole role,
        std::vector<uint8_t> &templ,
        std::vector<EyePair> &eyeCoordinates)
{
    /* Note: createTemplate() will not be in the Twins Demonstraion Track  */
    return ReturnStatus(ReturnCode::Success);
}

ReturnStatus
NullImplFRVT11_TWINS::createTemplate(
    const FRVT::Image &image,
    FRVT::TemplateRole role,
    std::vector<std::vector<uint8_t>> &templs,
    std::vector<FRVT::EyePair> &eyeCoordinates)
{
    int numFaces = rand() % 4 + 1;
    for (int i = 1; i <= numFaces; i++) {
        std::vector<uint8_t> templ;
        /* Note: example code, potentially not portable across machines. */
        std::vector<float> fv = {1.0, 2.0, 8.88, 765.88989};
        /* Multiply vector values by scalar */
        for_each(fv.begin(), fv.end(), [i](float &f){ f *= i; });
        const uint8_t* bytes = reinterpret_cast<const uint8_t*>(fv.data());
        int dataSize = sizeof(float) * fv.size();
        templ.resize(dataSize);
        memcpy(templ.data(), bytes, dataSize);
        templs.push_back(templ);

        eyeCoordinates.push_back(EyePair(true, true, i, i, i+1, i+1));
    } 
    
    return ReturnStatus(ReturnCode::Success);
}

ReturnStatus
NullImplFRVT11_TWINS::matchTemplates(
        const std::vector<uint8_t> &verifTemplate,
        const std::vector<uint8_t> &enrollTemplate,
        double &similarity)
{
    /*
    float *featureVector = (float *)enrollTemplate.data();

    for (unsigned int i=0; i<this->featureVectorSize; i++) {
	std::cout << featureVector[i] << std::endl;
    }
    */

    similarity = rand() % 1000 + 1;
    return ReturnStatus(ReturnCode::Success);
}

std::shared_ptr<Interface>
Interface::getImplementation()
{
    return std::make_shared<NullImplFRVT11_TWINS>();
}





