//v1: uses std::multiset
//v2: uses std::vector

/*TRADE-OFFS:
main difference: const-correctness of span methods

MULTISET:
- always sorted
- handles duplicates (instead of set)
- shortest span is O(n), walk all neighbors
- longest span is trivial O(1) (begin - end)
=> cleaner API, longest and shortest span are naturally const
- iterators are bidirectional, not random access (set.begin() + 1 doesn't compile)
- enforce _size manually, no builtin size limit (for addRange)
- memory overhead is theoretically higher, but irrilevant for 10.000 elements
- std::multiset::insert(begin, end) doesn't give a strong atomicity guarantee if the custom limit is hit halfway:
 might need to iterate manually or check before if the entire range fits and choose an implementation-defined behaviour (either insert until limit or refuse everything)

VECTOR:
- sorting on-demand (either on insertion or before calling shortest/longest span)
=> SOURCE OF BUGS: vector sorting invalidation, if you sort-on-demand inside shortestSpan() / longestSpan(), what happens when addNumber() is called after?
 The new element is appended at the end, so vector is no longer sorted. 
 You now need a _isSorted flag, or you must re-sort on every span query, or you must insert in sorted position (making addNumber O(n)).
- handles duplicates
- since it's sorted, it has the same algorithmic properties as multiset
=> shortest span is O(n), walk all neighbors (+ sorting)
=> longest span is trivial (begin - end) (+ sorting)
- API cannot be const if it's modified in place OR
 needs mutable on vector member (smells) OR
 needs to sort a copy, O(n log n) every call (slower)
- iterators are random access, vec.begin() + 1 is ok
- memory overhead is minimal
- std::vector::insert(pos, begin, end) does not enforce a strong atomicity guarantee on custom limit just like multiset
- invariants must be maintained manually (likely more complex solution)
*/

#include <vector>
#include <set>

class Span {
private:
	Span();
	unsigned int _size;

public:
	Span(unsigned int);
	Span(const Span&);
	Span& operator=(const Span&);
	~Span();

	void addNumber(int);
	int shortestSpan();
	int longestSpan();

	// add range of iterators in one call
};