xdiff (via git) 
===============

This is the version of the xdiff file differential library used by [git](https://github.com/git/git).

This project began life as [LibXDiff](http://www.xmailserver.org/xdiff-lib.html) by Davide Libenzi, but has been modified to suit the git project's needs. Some unnecessary functionality has been removed and some new functionality has been added.

Fundamentally, this library is _meant for git_ but has been extracted into a standalone library for compatibility with other git-like projects, for example, [libgit2](https://github.com/libgit2/libgit2).

This repository tracks the git project as an upstream, and makes only minimal (with a goal of _zero_) changes to xdiff itself.

Inclusion in your application
-----------------------------

Although this project _is used by git_, it has no git-specific code explicitly inside it. git -- and other callers -- add application-specific code through the `git-xdiff.h` file. For example, if your application uses a custom `malloc`, then you can configure it in the `git-xdiff.h` file.

Contributions
-------------

Contributions to improve the build or compatibility of this library _as a standalone work of art_ are welcome. Contributions that change the diff functionality, however, _[should be made to git project itself](https://github.com/git/git/blob/master/Documentation/SubmittingPatches)_. (Once those changes land in git, thehy will be included here.)

Credits
-------

Many thanks to Davide Libenzi, the original author of LibXDiff, as well as the numerous contributors to git and libgit2 who have improved xdiff over the years.
