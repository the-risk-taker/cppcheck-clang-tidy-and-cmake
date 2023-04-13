namespace third_party
{
    struct fancy_struct_interface
    {
        ~fancy_struct_interface() = default;

        virtual void do_something() = 0;
    };

    struct fancy_struct_impl : public fancy_struct_interface
    {
        void do_something();
    };

}   // namespace third_party
