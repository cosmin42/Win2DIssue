// Copyright (c) Microsoft Corporation and Contributors.
// Licensed under the MIT License.

#pragma once

#include <winrt/Microsoft.Graphics.Canvas.UI.Xaml.h>
#include <winrt/Microsoft.Graphics.Canvas.UI.h>
#include <winrt/Microsoft.Graphics.Canvas.h>

#include "MainWindow.g.h"

using namespace winrt::Windows::Foundation::Collections;

namespace winrt::Example::implementation
{
    struct MainWindow : MainWindowT<MainWindow>
    {
        MainWindow();

        int32_t MyProperty();
        void MyProperty(int32_t value);

        void myButton_Click(Windows::Foundation::IInspectable const& sender, Microsoft::UI::Xaml::RoutedEventArgs const& args);
        
        void CanvasControlDraw([[maybe_unused]] winrt::Microsoft::Graphics::Canvas::
            UI::Xaml::CanvasControl const& sender,
            [[maybe_unused]] winrt::Microsoft::Graphics::Canvas::
            UI::Xaml::CanvasDrawEventArgs const& args)
        {
            auto session = args.DrawingSession();

            Microsoft::Graphics::Canvas::CanvasDevice device =
                Microsoft::Graphics::Canvas::CanvasDevice::GetSharedDevice();

            winrt::array_view<uint8_t const> view_name;

            const auto format = Microsoft::Graphics::DirectX::DirectXPixelFormat::
                B8G8R8A8UIntNormalized;
            auto const& f2 = format;

            winrt::Microsoft::Graphics::Canvas::ICanvasResourceCreator const& resource =
                device;

            winrt::Windows::Storage::Streams::IBuffer buffer;
            Microsoft::Graphics::Canvas::CanvasBitmap bitmap =
                Microsoft::Graphics::Canvas::CanvasBitmap::CreateFromBytes(
                    resource, view_name, (int32_t)3,
                    (int32_t)3, f2);

            session.DrawImage(bitmap);
        }
    };
}

namespace winrt::Example::factory_implementation
{
    struct MainWindow : MainWindowT<MainWindow, implementation::MainWindow>
    {
    };
}
