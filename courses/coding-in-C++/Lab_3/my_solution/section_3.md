# Section 3

## UML review

### Classes

Good points are:

- Most classes make their fields private for encapsulation
- Defined public methods for modifying the classes

Bad points are:

- A bunch of getters may be missing, so many private fields are inaccessible
- Book makes everythin public, but stuff like title or isbn should be made private with public getters to prevent outside modification
- printLocation() inside PrintedBook should probably be marked as {query}
- No Field specifies an extra property, e.g. {unique} could be used for Book's
ISBN or Librarian's employeeID
- No const restrictions in functions even though they probably need some

### Relationships

Good points are:

- Librarian derives from Member; librarians can also borrow books
- PrintedBook and EBook derive from Book, both act as books and share code

Bad points are:

- Librarian should be composited with Library; the employeeId implies the Librarian is registered in a specific library and cannot exist without one
- Member should be composited with Library; Members cannot exist without a library
- Book should be associated with library, they exist independently of each other, and a book can belong in multiple libraries.
- Book should be associated with Member; Member needs to know about borrowed books.
- EBook and Book association makes no sense
- Loan should be composited with Book or Member, not with just EBook
- Member Loan association should be limited as shown in Member::borrowed multiplicity
