#pragma once

#include <picotorrent/ui/property_sheets/property_sheet_page.hpp>
#include <map>
#include <string>
#include <vector>

#include <commctrl.h>
#include <uxtheme.h>

namespace picotorrent
{
namespace ui
{
namespace property_sheets
{
namespace details
{
    class peers_page : public property_sheet_page
    {
    public:
        peers_page();

        void add_peer(const std::string &pid, const std::wstring &ip, int port);
        void begin_update();
        void end_update();
        bool has_peer(const std::string &pid);
        void update_peer(const std::string &pid, const std::wstring &client, const std::wstring &flags, int dl, int ul);

    protected:
        BOOL on_command(HWND hDlg, UINT uCtrlId, WPARAM wParam, LPARAM lParam);
        void on_init_dialog();
        bool on_notify(HWND hDlg, LPNMHDR nmhdr, LRESULT &result);

    private:
        struct peer_item
        {
            std::string pid;
            std::wstring ip;
            int port;
            std::wstring client;
            std::wstring flags;
            int dl;
            int ul;
            bool clean;
        };

        std::vector<peer_item> peers_;

    };
}
}
}
}
