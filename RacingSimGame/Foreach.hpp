#ifndef RACE_FOREACH_HPP
#define RACE_FOREACH_HPP

// Preprocessor trick to allow nested loops
#define RACE_PP_CAT_IMPL(a, b) a ## b
#define RACE_PP_CAT(a, b) RACE_PP_CAT_IMPL(a, b)
#define RACE_ID(identifier) RACE_PP_CAT(auroraDetail_, identifier)
#define RACE_LINE_ID(identifier) RACE_PP_CAT(RACE_ID(identifier), __LINE__)


// Macro to emulate C++11 range-based for loop
// Instead of for (decl : range) you write FOREACH(decl, range) as in the following example
//
// std::vector<int> v = ...;
// FOREACH(int& i, v)
// {
//     i += 2;
// }
#define FOREACH(declaration, container)																											\
	if (bool RACE_LINE_ID(broken) = false) {} else																								\
	for (auto RACE_LINE_ID(itr) = (container).begin(); RACE_LINE_ID(itr) != (container).end() && !RACE_LINE_ID(broken); ++RACE_LINE_ID(itr))	\
	if (bool RACE_LINE_ID(passed) = false) {} else																								\
	if (RACE_LINE_ID(broken) = true, false) {} else																								\
	for (declaration = *RACE_LINE_ID(itr); !RACE_LINE_ID(passed); RACE_LINE_ID(passed) = true, RACE_LINE_ID(broken) = false)

#endif // RACE_FOREACH_HPP