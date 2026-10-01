# Testing Log — MFMS Project A

## Module 1: Employee Management
| Test Case | Expected | Actual | Result |
|-----------|----------|--------|--------|
| Add employee ID 101 | Saved | Saved correctly | Pass |
| Display all employees | Shows all records | Shows all | Pass |
| Search ID 101 | Finds employee | Found with details | Pass |
| Search ID 999 | Not found | "Not found" message | Pass |

## Module 2: Budget Management
| Test Case | Expected | Actual | Result |
|-----------|----------|--------|--------|
| Add budget 500,000 | Saved | Saved | Pass |
| Record expenditure 420,000 | Deducted | Deducted | Pass |
| Check over-budget | Flags dept over limit | Flagged correctly | Pass |

## Module 3: Supplier Management
| Test Case | Expected | Actual | Result |
|-----------|----------|--------|--------|
| Add supplier ABC | Saved | Saved | Pass |
| Search ABC | Found | Found | Pass |
| Search XYZ | Not found | "Not found" | Pass |

## Module 4: Asset Management
| Test Case | Expected | Actual | Result |
|-----------|----------|--------|--------|
| Add asset Laptop | Saved | Saved | Pass |
| Search asset ID | Found | Found | Pass |
| Search invalid ID | Not found | "Not found" | Pass |

## Module 5: Reports
| Test Case | Expected | Actual | Result |
|-----------|----------|--------|--------|
| Employee report | Shows totals | Shows totals | Pass |
| Budget report | Shows summary | Shows summary | Pass |
| Supplier report | Shows list | Shows list | Pass |
| Asset report | Shows total value | Shows value | Pass |

## Module 6: Integration & Menu
| Test Case | Expected | Actual | Result |
|-----------|----------|--------|--------|
| Main menu displays | Shows all 6 options | Correct | Pass |
| Invalid choice (99) | Error message | "Invalid choice" | Pass |
| Exit (option 6) | Program quits | Quit cleanly | Pass |
