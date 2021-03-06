#ifndef _SPEC_H_
#define _SPEC_H_

enum
{
    STMT_address,
    STMT_after,
    STMT_align,
    STMT_beginseg,
    STMT_endseg,
    STMT_entry,
    STMT_flags,
    STMT_include,
    STMT_include_data_with_rodata,
    STMT_name,
    STMT_number,
    STMT_romalign,
    STMT_stack,
    STMT_increment,
    STMT_pad_text,
};

enum
{
    FLAG_BOOT = (1 << 0),
    FLAG_OBJECT = (1 << 1),
    FLAG_RAW = (1 << 2),
};

struct Include
{
    char *fpath;
    int linkerPadding;
    uint8_t dataWithRodata;
};

struct Segment
{
    uint32_t fields;
    char *name;
    char *after;
    uint32_t flags;
    uint32_t address;
    uint32_t stack;
    uint32_t align;
    uint32_t romalign;
    uint32_t increment;
    uint32_t entry;
    uint32_t number;
    struct Include *includes;
    int includesCount;
};

void parse_rom_spec(char *spec, struct Segment **segments, int *segment_count);

void free_rom_spec(struct Segment *segments, int segment_count);

#endif
