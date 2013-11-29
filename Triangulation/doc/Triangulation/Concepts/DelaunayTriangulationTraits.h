
/*!
\ingroup PkgTriangulationsConcepts
\cgalConcept

The concept `DelaunayTriangulationTraits` describes the various types and functions that a class
has to provide as the first parameter (`DCTraits`) to the class template
`Delaunay_triangulation<DelaunayTriangulationTraits, TriangulationDataStructure>`. 

It brings the geometric ingredients to the definition of a Delaunay
complex, while the combinatorial ingredients are brought by the second
template parameter, `TriangulationDataStructure`.

\cgalRefines ::TriangulationTraits.

\cgalHasModel `CGAL::Cartesian_d<FT, Dim, LA>`
\cgalHasModel `CGAL::Simple_cartesian_d<FT, Dim, LA>`
\cgalHasModel `CGAL::New_kernel_d` (recommended when available)

\sa `TriangulationTraits`
\sa `DelaunayTriangulation`
*/
class DelaunayTriangulationTraits {
public:

/// \name Types
/// @{

/*!
A predicate object that must provide
the templated operator
`template<typename ForwardIterator> Oriented_side operator()(ForwardIterator start, ForwardIterator end, const Point_d & p)`.
The operator returns `ON_POSITIVE_SIDE`,
`ON_NEGATIVE_SIDE`
or `ON_ORIENTED_BOUNDARY` depending of the side of the query
point `p`
with respect to the sphere circumscribing the simplex
defined by the points in range `[start,end)`.
If the simplex is positively
oriented, then the positive side of sphere corresponds geometrically
to its bounded side.
\pre `std::distance(start,end)=D+1`, where
`Point_dimension_d(*it)` is \f$ D\f$ for all `it` in
`[start,end)`. `Point_dimension_d(p)` is also \f$ D\f$.
The points in range
`[start,end)` must be affinely independent, i.e., the simplex must
not be flat.
*/
typedef Hidden_type Side_of_oriented_sphere_d;

/*!
A predicate object that must
provide the templated operator

`template<typename ForwardIterator> Oriented_side operator()(Flat_orientation_d orient, ForwardIterator start, ForwardIterator end, const Point_d & p)`.

The operator returns `ON_POSITIVE_SIDE`,
`ON_NEGATIVE_SIDE`
or `ON_ORIENTED_BOUNDARY` depending of the side of the query
point `p`
with respect to the sphere circumscribing the simplex
defined by the points in range `[start,end)`.
If the simplex is positively
oriented according to `orient`,
then the positive side of sphere corresponds geometrically
to its bounded side.
The points in range `[start,end)` and `p` are supposed to belong to the lower dimensional flat
whose orientation is given by `orient`.
\pre `std::distance(start,end)=k+1` where \f$ k\f$ is the number of
points used to construct `orient`.
`Point_dimension_d(*it)` is \f$ D\f$ for all `it` in
`[start,end)`. `Point_dimension_d(p)` is also \f$ D\f$.
The points in range
`[start,end)` must be affinely independent, i.e., the simplex must
not be flat.

*/
typedef Hidden_type In_flat_side_of_oriented_sphere_d;

/// @}

/// \name Creation
/// @{

/*!
The default constructor.
*/
DelaunayTriangulationTraits();

/// @}

/// \name Operations
/// The following methods permit access to the traits class's predicates:
/// @{

/*!

*/
Side_of_oriented_sphere_d side_of_oriented_sphere_d_object() const;

/*!

*/
In_flat_side_of_oriented_sphere_d in_flat_side_of_oriented_sphere_d_object()
const;

/// @}

}; /* end DelaunayTriangulationTraits */
