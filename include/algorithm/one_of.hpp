#ifndef _ONE_OF_HPP_INCLUDED_SOFIJ3W498YSAFKJH984YTHAKFSHDASFKLJHASFIUHRTIUHAFIUHGFDASI8GURHETIUHFSA
#define _ONE_OF_HPP_INCLUDED_SOFIJ3W498YSAFKJH984YTHAKFSHDASFKLJHASFIUHRTIUHAFIUHGFDASI8GURHETIUHFSA

#include <cstddef>

namespace feng
{

namespace one_of_private
{

    template< typename Predicate, typename First_Input_Iterator, typename ... Rest_Input_Iterators >
    std::size_t _one_of_count( Predicate predict, First_Input_Iterator first, First_Input_Iterator last, Rest_Input_Iterators ... rest )
    {
        if ( first == last ) return 0;
        return ( predict( *first++, *rest++...) ? 1 : 0 ) + _one_of_count( predict, first, last, rest... );
    }

    struct dummy{};

    template<typename Predicate, typename ... Input_Iterators>
    std::size_t rotate_one_of_count_impl( Predicate predict, dummy, Input_Iterators ... inputs )
    {
        return _one_of_count( predict, inputs ... );
    }
    
    template<typename Anonymous_Arg1, typename ... Anonymous_Argn>
    std::size_t rotate_one_of_count_impl( Anonymous_Arg1 arg1, Anonymous_Argn ... argn )
    {
        return rotate_one_of_count_impl( argn ..., arg1 );
    }

}//namespace one_of_private

    //example:
    //      int a[4] = { 1, 2, 3, 4 };
    //      int A[4] = { 2, 4, 6, 8 };
    //      bool b = feng::one_of( a, a+4, A, [](int a_, int A_){ return a_+a_ == A_;} );
    template<typename ... Input_Iterators_and_Predict>
    bool one_of( Input_Iterators_and_Predict ... all_args )
    {
        static_assert( sizeof ... ( all_args ) > 2, "feng::one_of requires at least 3 arguments" );
        return 1 == one_of_private::rotate_one_of_count_impl( all_args ..., one_of_private::dummy() );
    }

}//namespace feng

#endif//_ONE_OF_HPP_INCLUDED_SOFIJ3W498YSAFKJH984YTHAKFSHDASFKLJHASFIUHRTIUHAFIUHGFDASI8GURHETIUHFSA
