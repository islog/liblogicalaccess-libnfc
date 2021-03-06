/**
 * \file nfcreadercardadapter.hpp
 * \author Maxime C. <maxime-dev@islog.com>
 * \brief Default NFC reader/card adapter.
 */

#ifndef LOGICALACCESS_DEFAULTNFCREADERCARDADAPTER_HPP
#define LOGICALACCESS_DEFAULTNFCREADERCARDADAPTER_HPP

#include <logicalaccess/plugins/cards/iso7816/readercardadapters/iso7816readercardadapter.hpp>
#include <logicalaccess/plugins/readers/nfc/nfcreaderprovider.hpp>

#include <string>
#include <vector>

#include <logicalaccess/plugins/llacommon/logs.hpp>

namespace logicalaccess
{
/**
 * \brief A default NFC reader/card adapter class.
 */
class LLA_READERS_NFC_NFC_API NFCReaderCardAdapter : public ISO7816ReaderCardAdapter
{
  public:
    /**
     *\ brief Constructor.
     */
    NFCReaderCardAdapter();

    /**
     * \brief Destructor.
     */
    virtual ~NFCReaderCardAdapter();

    /**
     * \brief Adapt the command to send to the reader.
     * \param command The command to send.
     * \return The adapted command to send.
     */
    std::vector<unsigned char>
    adaptCommand(const std::vector<unsigned char> &command) override;

    /**
     * \brief Adapt the asnwer received from the reader.
     * \param answer The answer received.
     * \return The adapted answer received.
     */
    std::vector<unsigned char>
    adaptAnswer(const std::vector<unsigned char> &answer) override;

    /**
     * We override this because a 0 byte return is valid with libnfc.
     */
    std::vector<unsigned char> sendCommand(const std::vector<unsigned char> &command,
                                           long timeout = 3000) override;

    /**
     * Set the Ignore All Error flag to `ignore`.
     *
     * This is useful when we want to do hacky thing that are expected to
     * raise error.
     * It returns the previous value of the flag.
     */
    bool ignoreAllError(bool ignore);

    /**
     * Return the value of the Ignore All Error flag
     */
    bool ignoreAllError() const;

  protected:
    bool ignore_error_;
};
}

#endif /* LOGICALACCESS_DEFAULTNFCREADERCARDADAPTER_HPP */
