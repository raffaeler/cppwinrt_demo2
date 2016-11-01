//
// MainPage.xaml.cpp
// Implementation of the MainPage class.
//

#include "pch.h"
#include "MainPage.xaml.h"

#pragma comment(lib, "windowsapp")
#include "winrt\base.h"
#include "winrt\Windows.Networking.h"
#include "winrt\Windows.Foundation.h"
#include "winrt\Windows.Web.Syndication.h"

#include "winrt\Windows.ApplicationModel.h" 
#include "winrt\Windows.ApplicationModel.Activation.h" 
#include "winrt\Windows.UI.Xaml.h"
#include "winrt\Windows.UI.Xaml.Controls.h"
//#include <winrt\Windows.UI.Xaml.Media.h>
#include "CppWinrtHelper.h"

using namespace SimpleApp;

namespace w
{
    using namespace winrt;
    using namespace winrt::Windows;
    using namespace winrt::Windows::Foundation;
    using namespace winrt::Windows::Networking;
    using namespace winrt::Windows::Web::Syndication;
    using namespace winrt::Windows::UI;
    using namespace winrt::Windows::UI::Xaml;
    using namespace winrt::Windows::UI::Xaml::Media;
    using namespace winrt::Windows::UI::Xaml::Controls;
}

MainPage::MainPage()
{
	InitializeComponent();

    w::SyndicationClient client;
    auto x = client.Timeout();

    w::Window window = w::Window::Current();
}


void SimpleApp::MainPage::Button_Click(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e)
{
    auto button = copyRT<
        w::ABI::Windows::UI::Xaml::Controls::IButton*,
        Platform::Object^,
        w::Button>(sender);

    //button.Content(winrt::Windows::Foundation::PropertyValue::CreateString(L"Ciao!"));

    auto block = copyRT <
        winrt::ABI::Windows::UI::Xaml::Controls::ITextBlock*,
        Windows::UI::Xaml::Controls::TextBlock^,
        w::TextBlock>(textBlock);

	w::Button bt;
	bt.Content(w::PropertyValue::CreateString(L"Push me"));
	bt.FontSize(48.0);
	bt.Width(200.0);
	w::Grid::SetRow(bt, 3);

	auto parent = block.Parent().as<w::Grid>();
	parent.Children().InsertAt(0, bt);

    block.Text(L"Welcome to cppwinrt");
    block.VerticalAlignment(w::VerticalAlignment::Center); // winrt::Windows::UI::Xaml::
    block.TextAlignment(w::TextAlignment::Center);     // winrt::Windows::UI::Xaml::
    block.FontSize(48.0);

    //block.FontFamily(w::FontFamily(L"Calibri"));      // Windows::UI::Xaml::Media::
    //block.Foreground(w::SolidColorBrush(w::Colors::Navy())); // Windows::UI::Xaml::Media::     winrt::Windows::UI::
}
