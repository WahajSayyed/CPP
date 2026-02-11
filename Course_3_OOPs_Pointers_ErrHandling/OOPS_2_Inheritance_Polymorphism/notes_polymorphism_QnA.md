````int main() {
    // Create a playlist of different media types
    vector<unique_ptr<MediaFile>> playlist;

    playlist.push_back(make_unique<AudioFile>(
        "song.mp3", 210.5, 5000000, 320, "MP3"));

    playlist.push_back(make_unique<VideoFile>(
        "movie.mp4", 7200.0, 2000000000, "1080p", 60, "H.264"));

    playlist.push_back(make_unique<AudioFile>(
        "podcast.wav", 1800.0, 150000000, 1411, "WAV"));

    cout << "\n--- Playing Playlist ---\n" << endl;

    // Polymorphic behavior
    for (const auto& media : playlist) {
        media->displayInfo();
        media->play();
        media->pause();
        media->stop();
        cout << "------------------------" << endl;
    }

    cout << "\n--- End of Program ---\n" << endl;

    // No manual delete needed — unique_ptr cleans up automatically
    return 0;
}

````

# Question: Why use pointer to create vector elements?

Great question — this gets to the **heart of polymorphism in C++** 👌
The short version is: **because polymorphism only works through pointers or references**.

Let’s unpack it properly.

---

## 1. The core problem: objects vs inheritance

You want this:

```cpp
vector<MediaFile> playlist;
```

and then:

```cpp
playlist.push_back(AudioFile(...));
playlist.push_back(VideoFile(...));
```

### ❌ Why this does NOT work

Because `vector<MediaFile>` can only store **MediaFile objects**.

When you try to insert a derived object:

```cpp
AudioFile → MediaFile
```

C++ performs **object slicing**:

* The `AudioFile`-specific parts are cut off
* Only the `MediaFile` subobject is stored

Even worse in your case:

* `MediaFile` is **abstract**
* You can’t even create a `MediaFile` object

So this is impossible.

---

## 2. Why pointers fix this

Instead, we do:

```cpp
vector<unique_ptr<MediaFile>> playlist;
```

Now the vector stores:

* Pointers of **one fixed size**
* Each pointer can point to a **different derived type**

Example:

```cpp
MediaFile* → AudioFile
MediaFile* → VideoFile
```

✔ No slicing
✔ Correct runtime behavior
✔ One container, many types

---

## 3. Polymorphism requires indirection

Virtual functions work only when called through:

* a **base-class pointer**, or
* a **base-class reference**

Example:

```cpp
MediaFile* m = new AudioFile(...);
m->play();   // Calls AudioFile::play()
```

If you stored objects **by value**, this would be impossible.

---

## 4. Why `unique_ptr` specifically (and not raw pointers)

You *could* write:

```cpp
vector<MediaFile*> playlist;
```

But then you must manually `delete` everything.

`unique_ptr` gives you:

* Automatic destruction
* Exception safety
* Clear ownership semantics

```cpp
vector<unique_ptr<MediaFile>> playlist;
// cleanup happens automatically
```

Best practice in modern C++ 👍

---

## 5. Why not references?

Because:

* References cannot be reseated
* Containers can’t store references directly

So pointers are the only viable option.

---

## 6. Mental model 🧠

Think of it like this:

> A `vector` needs all elements to be the same **size**
> Derived objects have **different sizes**
> Pointers all have the same size

So we store **pointers to polymorphic objects**, not the objects themselves.

---

## Final takeaway

* **Polymorphism needs pointers or references**
* **Vectors need same-sized elements**
* **Pointers prevent slicing**
* **`unique_ptr` gives safe ownership**
---




# Question: Can you elaborate the mental model further?
---
Absolutely — this is a *really* good instinct to dig into. Let’s build a **clear mental picture**, not just rules to memorize.

---

## The core mental model:

### **“A container is a box of identical slots.”**

Think of a `vector` like this:

```
| slot | slot | slot | slot |
```

Every **slot** must:

* Have the **same size**
* Have the **same layout**
* Be known at **compile time**

That’s non-negotiable.

---

## Step 1: Sizes matter (a lot)

Your classes:

```
MediaFile
AudioFile   (MediaFile + bitRate + audioFormat)
VideoFile   (MediaFile + resolution + frameRate + codec)
```

These objects look like:

```
MediaFile object:
[ filename | duration | fileSize ]

AudioFile object:
[ MediaFile | bitRate | audioFormat ]

VideoFile object:
[ MediaFile | resolution | frameRate | codec ]
```

Different sizes. Different layouts.

So this is impossible:

```cpp
vector<MediaFile> v;
v.push_back(AudioFile(...)); // ❌
```

Because the vector says:

> “I only have room for `MediaFile`, not extra stuff.”

That extra stuff gets **sliced off**.

---

## Step 2: Object slicing (what really happens)

When you do:

```cpp
AudioFile a;
MediaFile m = a;
```

Memory-wise:

```
AudioFile:
[ MediaFile | AudioFile-only data ]

After assignment:
[ MediaFile ]   // Audio part is gone
```

This is **object slicing**.

Now ask yourself:

> How could `play()` ever call `AudioFile::play()`
> if the `AudioFile` part no longer exists?

It can’t.

---

## Step 3: Why pointers solve everything

Now switch the mental model.

Instead of storing **objects**, store **addresses**.

```cpp
vector<MediaFile*> v;
```

Memory looks like:

```
vector:
[ ptr ] [ ptr ] [ ptr ]

heap:
AudioFile object
VideoFile object
AudioFile object
```

Key insight:

> **All pointers are the same size**

So the vector is happy:

```
| 8 bytes | 8 bytes | 8 bytes |
```

Each pointer says:

> “Go look over there for the real object.”

---

## Step 4: Where polymorphism actually lives

Virtual functions work like this (simplified):

```
object memory:
[ vptr | data... ]
```

That `vptr` points to a **vtable** that says:

* “If `play()` is called, jump to AudioFile::play()”
* or “jump to VideoFile::play()”

But this only works when:

```cpp
MediaFile* p = new AudioFile();
p->play();   // runtime lookup
```

If you store by value:

* No pointer
* No runtime lookup
* No polymorphism

---

## Step 5: Why references don’t work in containers

You might think:

> “Why not `vector<MediaFile&>`?”

Because references:

* Must be initialized immediately
* Cannot be reseated
* Are not objects

A container needs to:

* Move elements
* Reallocate memory
* Assign and destroy elements

References break all of that.

So: **no references in containers**.

---

## Step 6: Why `unique_ptr` is the “grown-up” version

Raw pointer version:

```cpp
vector<MediaFile*> v;
```

Problem:

* Who deletes the objects?
* What if an exception happens?

`unique_ptr` says:

> “This vector OWNS these objects.”

Memory layout:

```
vector:
[ unique_ptr ] [ unique_ptr ]

heap:
AudioFile
VideoFile
```

When the vector dies:

```
~unique_ptr → delete → virtual destructor chain
```

Safe. Predictable. No leaks.

---

## Step 7: The one-sentence mental model 🧠

> **Containers store values of one fixed size.
> Polymorphism needs objects of different sizes.
> So we store same-sized pointers to different-sized objects.**

If that sentence clicks, everything else follows naturally.

---

## Bonus intuition (real-world analogy)

Think of a parking garage:

* **Parking spots** = vector slots (same size)
* **Vehicles** = objects (different sizes)
* **License plate numbers** = pointers

You don’t store cars *inside* the garage office.
You store **identifiers** that tell you *where the car is*.
