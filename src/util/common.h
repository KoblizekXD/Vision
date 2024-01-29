#ifndef COMMON_H
#define COMMON_H

template <class T, void Setter(T)>
class Property {
private:
    T* value;
public:
    Property(T _value) {
        value = &_value;
    }
    void operator=(T value) {
        Setter(value);
    }
};

#define PROPERTY(TYPE, NAME, ONSET) static TYPE Set##NAME(TYPE value) ONSET \
    static Property<TYPE, &Set##NAME> NAME;

class X {
public:
    PROPERTY(int, Abc, {

    })
};

// https://stackoverflow.com/a/40560508
template <class T, class Object, T(Object::*real_setter)(T const &)>
class RWProperty
{
    Object * my_object;
public:
    RWProperty() : my_object(0) {}
    RWProperty(Object * me = 0) : my_object(me) {}
    void operator()(Object * obj) { my_object = obj; }
    T set(T const & value) { return (my_object->*real_setter)(value); }
    T operator=(T const & value) { return (my_object->*real_setter)(value); }
    typedef T value_type;
};

#endif //COMMON_H
