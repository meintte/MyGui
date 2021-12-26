#pragma once

namespace mygui {
    using MouseCode = uint16_t;

    namespace Mouse {
        enum : MouseCode {
            Button0 = 0,
            Button1 = 1,
            Button2 = 2,
            Button3 = 3,
            Button4 = 4,
            Button5 = 5,
            Button6 = 6,
            Button7 = 7,

            // clang-format off
            ButtonLast      = Button7,
            ButtonLeft      = Button0,
            ButtonRight     = Button1,
            ButtonMiddle    = Button2
            // clang-format on
        };
    }
}  // namespace mygui